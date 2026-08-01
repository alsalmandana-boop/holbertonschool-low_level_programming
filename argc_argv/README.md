# argc_argv

## 📌 Overview

This project introduces **command-line arguments** in C and demonstrates how programs receive input directly from the terminal. It covers the use of `argc` and `argv`, argument validation, string-to-integer conversion, and building command-line utilities.

---

## 🎯 Learning Objectives

By completing this project, I learned how to:

- Understand how command-line arguments are passed to a C program.
- Use `argc` to determine the number of arguments.
- Access command-line arguments using `argv`.
- Handle missing or invalid arguments safely.
- Convert strings to integers using `atoi()`.
- Build command-line applications following C best practices.

---

## 🧠 Key Concepts

- Command-Line Arguments
- `argc`
- `argv`
- `main()` Prototypes
- `atoi()`
- Argument Validation
- Input Processing

---

## 📂 Project Structure

```text
argc_argv/
│── 0-whatsmyname.c
│── 1-args.c
│── 2-args.c
│── 3-mul.c
│── 4-add.c
│── 100-change.c
│── main.h
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

```bash
$ ./my_program Hello World
```

Program receives:

```text
argc = 3

argv[0] = "./my_program"
argv[1] = "Hello"
argv[2] = "World"
```

---

## 📚 What I Learned

This project helped me understand how Linux passes arguments to programs through the `main()` function. I learned that every program receives its own name as `argv[0]`, how to process user input from the terminal, and how to validate command-line arguments before using them.

---

## 🔬 Biomedical Software Connection

Many scientific and biomedical applications are executed from the command line.

Examples include tools for:

- DNA sequence alignment
- Genome analysis
- Protein sequence processing
- Bioinformatics pipelines

Understanding `argc` and `argv` provides the foundation for building command-line tools that process research data, accept input files, configure analysis options, and automate scientific workflows.

---

## 🛠️ Skills

- C Programming
- Command-Line Programming
- Argument Parsing
- Input Validation
- Linux
- Problem Solving
- Software Engineering

---

## 👩‍💻 Author

**Danah Alsalman**

Software Engineering Student at Holberton School | Biology Graduate

Passionate about building reliable software and continuously developing the skills needed to contribute to scientific computing, healthcare technologies, and biomedical research.
