# Singly Linked Lists

## Description

This project introduces singly linked lists in C.

The goal is to understand how linked lists work, how they differ from arrays,
and how to create, traverse, and manipulate linked list nodes using pointers
and dynamic memory.

## Learning Objectives

By the end of this project, I should be able to explain:

- When and why to use linked lists instead of arrays
- How singly linked lists work
- How to create and traverse a linked list
- How to access the data stored in each node
- How pointers connect nodes together
- How to manage memory when working with linked lists

## Data Structure

The following structure is used throughout the project:

```c
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;
