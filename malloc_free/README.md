# C - malloc, free

## Description

This project introduces dynamic memory allocation in C using `malloc` and `free`. The goal is to understand how to allocate memory during program execution, initialize dynamically allocated memory, release allocated memory correctly, and avoid memory leaks.

## Learning Objectives

After completing this project, I learned how to:

- Understand the difference between automatic and dynamic memory allocation.
- Allocate memory using `malloc()`.
- Release allocated memory using `free()`.
- Check the return value of `malloc()`.
- Prevent memory leaks by freeing allocated memory.
- Use Valgrind to detect memory leaks and invalid memory access.

## Requirements

- Ubuntu 20.04 LTS
- GCC compiler
- Compilation flags:
  ```bash
  gcc -Wall -Werror -Wextra -pedantic -std=gnu89
  ```
- Betty coding style

## Files

| File | Description |
|------|-------------|
| `0-create_array.c` | Creates an array of characters and initializes it with a specific character. |
| `1-strdup.c` | Returns a pointer to a newly allocated space containing a copy of a string. |
| `2-str_concat.c` | Concatenates two strings into newly allocated memory. |
| `3-alloc_grid.c` | Creates a two-dimensional array of integers. |
| `4-free_grid.c` | Frees a two-dimensional grid created by `alloc_grid`. |

## Author

Dana AlSalman
