# Variadic Functions

## 📌 Overview

This project introduces **Variadic Functions** in C, allowing functions to accept a variable number of arguments. It focuses on using the macros provided by `<stdarg.h>` to access arguments safely and efficiently.

---

## 🎯 Learning Objectives

By completing this project, I learned how to:

- Understand variadic functions in C.
- Use `va_list` to access variable arguments.
- Initialize argument lists using `va_start`.
- Retrieve arguments using `va_arg`.
- Properly clean up using `va_end`.
- Apply the `const` qualifier correctly.

---

## 🧠 Key Concepts

- Variadic Functions
- `stdarg.h`
- `va_list`
- `va_start`
- `va_arg`
- `va_end`
- Function Prototypes
- Const Qualifier

---

## 📂 Project Structure

```text
variadic_functions/
│── 0-sum_them_all.c
│── 1-print_numbers.c
│── 2-print_strings.c
│── 3-print_all.c
│── variadic_functions.h
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
int sum;

sum = sum_them_all(4, 98, 1024, 402, -1024);

printf("%d\n", sum);
```

Output:

```text
500
```

---

## 📚 What I Learned

This project helped me understand how C handles functions that accept a variable number of arguments. I learned how the `stdarg.h` macros work together to iterate through arguments whose count is only known at runtime.

---

## 🔬 Biomedical Software Connection

Although variadic functions are less common than arrays or data structures in scientific applications, understanding them provides valuable insight into how low-level C libraries process flexible input.

This concept strengthens my understanding of memory layout, function calls, and API design—knowledge that is valuable when developing scientific software, biomedical tools, and high-performance research applications.

---

## 🛠️ Skills

- C Programming
- Variadic Functions
- stdarg.h
- Memory Fundamentals
- Function Design
- Problem Solving
- Software Engineering

---

## 👩‍💻 Author

**Danah Alsalman**

Software Engineering Student at Holberton School | Biology Graduate

Passionate about building reliable software and continuously developing the skills needed to contribute to scientific computing, healthcare technologies, and biomedical research.
