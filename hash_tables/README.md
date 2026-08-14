# Hash Tables

This project introduces hash tables and their implementation in the C programming language.

A hash table stores key-value pairs by using a hash function to convert a key into an index inside an array. Collisions are handled using separate chaining with linked lists.

## Learning Objectives

By the end of this project, I should be able to explain:

* What a hash function is
* What makes a good hash function
* What a hash table is and how it works
* How keys are converted into array indexes
* What a collision is
* How collisions can be handled using chaining
* The advantages and disadvantages of hash tables
* Common use cases for hash tables

## Data Structures

The project uses the following structures:

```c
/**
 * struct hash_node_s - Node of a hash table
 * @key: The key string
 * @value: The value associated with the key
 * @next: Pointer to the next node
 */
typedef struct hash_node_s
{
	char *key;
	char *value;
	struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table data structure
 * @size: Size of the array
 * @array: Array of pointers to hash nodes
 */
typedef struct hash_table_s
{
	unsigned long int size;
	hash_node_t **array;
} hash_table_t;
```

## Files

* `0-hash_table_create.c` — Creates a new hash table.
* `1-djb2.c` — Implements the djb2 hash function.
* `2-key_index.c` — Calculates the array index for a key.
* `3-hash_table_set.c` — Adds or updates a key-value pair.
* `4-hash_table_get.c` — Retrieves the value associated with a key.
* `5-hash_table_print.c` — Prints the hash table.
* `6-hash_table_delete.c` — Frees the complete hash table.
* `hash_tables.h` — Contains the data structures and function prototypes.

## Hashing Process

The key is converted into an array index in two steps:

```text
Key
 |
 v
hash_djb2(key)
 |
 v
Hash value
 |
 v
Hash value % table size
 |
 v
Array index
```

The index is calculated using:

```c
index = hash_djb2(key) % size;
```

## Collision Handling

This project uses separate chaining to handle collisions.

When two different keys produce the same index, their nodes are stored in a linked list at that array position:

```text
array[index]
     |
     v
[Node 1] -> [Node 2] -> NULL
```

## Compilation

All files are compiled on Ubuntu 20.04 LTS using:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c
```

Example for Task 2:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 \
2-main.c 1-djb2.c 2-key_index.c -o key_index
```

Run the executable with:

```bash
./key_index
```

## Requirements

* Betty coding and documentation style
* No global variables
* No more than five functions per file
* All files must end with a new line
* All function prototypes must be declared in `hash_tables.h`
* The header file must use an include guard

## Author

Dana Ibrahim Alsalman

