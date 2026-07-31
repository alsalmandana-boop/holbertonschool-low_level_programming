# Function Pointers

## 📌 Overview

This project explores **function pointers** in C and demonstrates how they can be used to write flexible, reusable, and modular code. It covers passing functions as arguments, invoking functions through pointers, and implementing callback-based designs.

---

## 🎯 Learning Objectives

By completing this project, I learned how to:

- Declare and use function pointers.
- Pass functions as arguments.
- Call functions through pointers.
- Build callback-based implementations.
- Write more modular and reusable C programs.

---

## 🧠 Key Concepts

- Function Pointers
- Callback Functions
- Function Prototypes
- Pointers
- Modular Programming
- Code Reusability

---

## 📂 Project Structure

```
function_pointers/
│── 0-print_name.c
│── 1-array_iterator.c
│── 2-int_index.c
│── 3-main.c
│── 3-op_functions.c
│── 3-get_op_func.c
│── 3-calc.h
│── function_pointers.h
│── README.md
```

---

## ⚙️ Compilation

Compile using:

```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 *.c -o output
```

---

## 🚀 Example

```c
void print_name(char *name, void (*f)(char *))
{
    if (name != NULL && f != NULL)
        f(name);
}
```

Example usage:

```c
print_name("Danah", print_name_as_is);
print_name("Danah", print_name_uppercase);
```

---

## 📚 What I Learned

This project helped me understand that in C, functions have memory addresses just like variables. Function pointers allow programs to dynamically choose which function to execute at runtime, making software more flexible and easier to extend.

---

## 🔬 Biomedical Software Connection

Function pointers are widely used in scientific and biomedical software where different algorithms may be selected dynamically at runtime.

For example, a DNA sequence analysis application may choose between multiple alignment algorithms depending on the input data, without changing the core application logic.

---

## 🛠️ Skills

- C Programming
- Function Pointers
- Callback Functions
- Pointers
- Software Design
- Modular Programming
- Problem Solving

---

## 👩‍💻 Author

**Danah Alsalman**

Biology Graduate transitioning into Software Engineering, with a long-term goal of building software for biomedical research and healthcare.
