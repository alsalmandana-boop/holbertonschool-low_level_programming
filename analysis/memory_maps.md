# AI Memory Visualizer

## 1. `stack_example.c`

### Program purpose

This program demonstrates recursion, stack frames, local-variable lifetimes, and temporary pointer aliasing.

`main()` calls:

```c
walk_stack(0, 3);
```

`walk_stack()` recursively calls itself until `depth` reaches `3`. Each active call has its own stack frame and its own `marker`.

The helper function `dump_frame()` is called once when entering a recursion level and once when leaving it. Each call to `dump_frame()` creates a separate temporary stack frame containing:

- `label`
- `depth`
- `local_int`
- `local_buf`
- `p_local`

### Important correction

`local_int`, `local_buf`, and `p_local` do **not** belong to the `walk_stack()` frame. They belong to the temporary `dump_frame()` frame.

`marker` belongs to the corresponding `walk_stack()` frame and remains alive while deeper recursive calls execute.

### Execution point 1: Entry into `main()`

```text
STACK
+----------------------------+
| main frame                 |
+----------------------------+

HEAP
No heap allocations.
```

The lifetime of the `main()` frame begins when the program enters `main()` and ends when `main()` returns.

### Execution point 2: `walk_stack(0, 3)` is active

```text
STACK
+--------------------------------+
| walk_stack frame: depth = 0    |
| max_depth = 3                  |
| marker = 0                     |
+--------------------------------+
| main frame                     |
+--------------------------------+

HEAP
No heap allocations.
```

The `marker` object belongs only to the `depth = 0` call.

### Execution point 3: `dump_frame("enter", 0)` is active

```text
STACK
+--------------------------------+
| dump_frame frame               |
| label -> "enter"               |
| depth = 0                      |
| local_int = 100                |
| local_buf = "A"                |
| p_local -> local_int           |
+--------------------------------+
| walk_stack frame: depth = 0    |
| marker = 0                     |
+--------------------------------+
| main frame                     |
+--------------------------------+

HEAP
No heap allocations.
```

`p_local` and `&local_int` contain the same address. Therefore, `p_local` is an alias of `local_int`.

When `dump_frame()` returns, the lifetimes of `local_int`, `local_buf`, and `p_local` end. The `marker` in `walk_stack(0, 3)` remains valid.

### Execution point 4: Maximum recursion depth

While `dump_frame("enter", 3)` is executing, the active frames are:

```text
TOP OF STACK

+--------------------------------+
| dump_frame frame               |
| depth = 3                      |
| local_int = 103                |
| local_buf = "D"                |
| p_local -> local_int           |
+--------------------------------+
| walk_stack frame: depth = 3    |
| marker = 30                    |
+--------------------------------+
| walk_stack frame: depth = 2    |
| marker = 20                    |
+--------------------------------+
| walk_stack frame: depth = 1    |
| marker = 10                    |
+--------------------------------+
| walk_stack frame: depth = 0    |
| marker = 0                     |
+--------------------------------+
| main frame                     |
+--------------------------------+

HEAP
No heap allocations.
```

There are four active `walk_stack()` frames, one temporary `dump_frame()` frame, and the `main()` frame.

Each recursive call has an independent `depth`, `max_depth`, and `marker`.

### Execution point 5: Returning from recursion

The recursive calls return in Last-In, First-Out order:

```text
depth 3
depth 2
depth 1
depth 0
main
```

When the `walk_stack(depth = 3)` call returns, only its frame is removed. The frames for depths `2`, `1`, and `0` remain valid until their own calls return.

For every exit message, a **new** call to `dump_frame("exit", depth)` creates new local objects. The exit-time `local_int` is not the same C object as the entry-time `local_int`, even if the compiler reuses the same stack address.

### Lifetime summary

- `main()` frame: valid until `main()` returns.
- Each `walk_stack()` frame: valid from function entry until that recursive call returns.
- `marker`: valid for the lifetime of its own `walk_stack()` call.
- Each `dump_frame()` local object: valid only during that individual call.
- No heap allocation exists in this program.

## 2. `aliasing_example.c`

### Program purpose

This program allocates an integer array on the heap, creates two aliases to the same allocation, frees the allocation through one pointer, and then accesses it through the other pointer.

### Execution point 1: Entry into `main()`

```text
STACK
+----------------------------+
| main frame                 |
| a = NULL                   |
| b = NULL                   |
| n = 5                      |
+----------------------------+

HEAP
No active allocations.
```

### Execution point 2: Entry into `make_numbers(5)`

```text
STACK
+----------------------------+
| make_numbers frame         |
| n = 5                      |
| i = 0                      |
| arr = NULL                 |
+----------------------------+
| main frame                 |
| a = NULL                   |
| b = NULL                   |
| n = 5                      |
+----------------------------+

HEAP
No active allocations yet.
```

### Execution point 3: After `malloc()`

```c
arr = malloc((size_t)n * sizeof(int));
```

Assuming allocation succeeds:

```text
STACK
+----------------------------+
| make_numbers frame         |
| n = 5                      |
| i = 0                      |
| arr -> H1                  |
+----------------------------+
| main frame                 |
| a = NULL                   |
| b = NULL                   |
| n = 5                      |
+----------------------------+

HEAP
H1: allocation for 5 integers
[uninitialized][uninitialized][uninitialized][uninitialized][uninitialized]
```

The lifetime of heap allocation `H1` begins when `malloc()` succeeds.

### Execution point 4: After the initialization loop

```text
HEAP
H1:
index 0 = 0
index 1 = 11
index 2 = 22
index 3 = 33
index 4 = 44
```

`arr` points to the first element of `H1`.

### Execution point 5: Return from `make_numbers()`

```c
return arr;
```

The pointer value stored in `arr` is copied into `a`.

```text
STACK
+----------------------------+
| main frame                 |
| a -> H1                    |
| b = NULL                   |
| n = 5                      |
+----------------------------+

HEAP
H1 = [0][11][22][33][44]
```

The `make_numbers()` frame is gone, so its local variables `n`, `i`, and `arr` no longer exist. However, `H1` remains valid because heap lifetime is not tied to the function's stack frame.

At this point, `main()` is responsible for eventually freeing `H1`.

### Execution point 6: After `b = a`

```c
b = a;
```

```text
STACK
+----------------------------+
| main frame                 |
| a -> H1                    |
| b -> H1                    |
| n = 5                      |
+----------------------------+

HEAP
H1 = [0][11][22][33][44]

ALIASES
a ──┐
    ├──> H1
b ──┘
```

The statement `b = a` copies only the address. It does not allocate a second array and does not copy the elements.

Therefore, `a[2]` and `b[2]` refer to the same integer object, whose value is `22`.

### Execution point 7: After `free(a)`

```c
free(a);
```

```text
STACK
+--------------------------------+
| main frame                     |
| a = former address of H1       |
| b = former address of H1       |
| n = 5                          |
+--------------------------------+

HEAP
H1 lifetime has ended.
The former allocation must not be accessed.
```

`free(a)` ends the lifetime of the heap allocation itself. It does not automatically set either pointer to `NULL`.

Both `a` and `b` now hold stale addresses and are dangling pointers.

### Execution point 8: Invalid read

```c
printf("  reading b[2]=%d\n", b[2]);
```

This is a use-after-free and an invalid read because `b` accesses an allocation whose lifetime has ended.

Printing `22` during one execution does not make the access valid. The behavior is undefined.

### Execution point 9: Invalid write

```c
b[3] = 1234;
```

This is a use-after-free and an invalid write. It writes through a dangling pointer into memory that is no longer owned by the program as allocation `H1`.

The fact that the program does not crash immediately does not prove safety.

### Ownership and lifetime summary

- `make_numbers()` creates `H1`.
- Ownership responsibility is transferred to the caller when the pointer is returned.
- `a` initially provides access to `H1`.
- `b = a` creates an alias, not a second allocation.
- `free(a)` ends the lifetime of the single shared allocation.
- Both aliases become dangling after the free.
- The later read and write are undefined behavior.

## 3. Critical Review of an AI Explanation

### Incomplete AI explanation

An AI explanation stated that every printed `local_int` in `stack_example.c` belongs directly to the corresponding recursive `walk_stack()` frame.

### Why this was inaccurate

`local_int` is declared inside `dump_frame()`, not inside `walk_stack()`. Each call to `dump_frame()` creates a temporary stack frame containing a new `local_int`.

The recursive `walk_stack()` frames contain `marker`, `depth`, and `max_depth`, while `dump_frame()` temporarily adds its own local variables above them.

Additionally, the entry and exit calls to `dump_frame()` create different `local_int` objects. Reuse of the same address does not mean they are the same object; their lifetimes do not overlap.

### Corrected explanation

At maximum recursion depth, the stack contains:

- the `main()` frame,
- four active `walk_stack()` frames for depths `0` through `3`,
- and one temporary `dump_frame()` frame.

`p_local` aliases `local_int` only during that specific `dump_frame()` call. When `dump_frame()` returns, both local objects cease to exist.

## Conclusion

The stack example demonstrates that each active function call has its own stack frame and lifetime. The aliasing example demonstrates that copying a pointer creates another alias to the same heap allocation, not another allocation. Freeing that shared allocation invalidates access through every alias.
