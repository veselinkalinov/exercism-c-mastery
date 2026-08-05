# University C Labs

C programming coursework, laboratory exercises, seminar tasks, self-study examples, and exam preparation materials completed as part of my Computer and Software Engineering studies at the Technical University of Sofia.

The repository documents my progression from basic C syntax and control flow to pointers, dynamic memory allocation, structures, and text and binary file processing. Each `.c` file is generally an independent console program created for a specific exercise or practice problem rather than part of one combined application.

## Topics covered

- C program structure, standard input and output, data types, and operators
- Conditional statements and iterative control flow
- Functions, parameters, return values, and variable scope
- One-dimensional and two-dimensional arrays
- Character arrays and common string operations
- Pointers and pointer-based function arguments
- Dynamic memory management with `malloc`, `calloc`, `realloc`, and `free`
- Structures, `typedef`, arrays of structures, and record processing
- Searching, filtering, sorting, updating, and deleting records
- Text-file processing with `fprintf`, `fscanf`, `fgets`, and related functions
- Binary-file processing with `fread`, `fwrite`, and file-position operations
- Basic debugging, compiler configuration, and automated exercise tests

## Repository structure

| Path | Contents |
| --- | --- |
| [`Laboratorni/`](./Laboratorni) | Laboratory work, organized by lab and date, progressing from introductory expressions to dynamic matrices, structures, and file operations. |
| [`Seminarni/`](./Seminarni) | Seminar exercise sets with source files and, where available, images of the original tasks. |
| [`Lekcii/`](./Lekcii) | Small examples written during lectures, including dynamic-memory demonstrations. |
| [`Samopodgotovka/`](./Samopodgotovka) | Additional self-study exercises on arrays, structures, pointers, and file access. |
| [`Exams/`](./Exams) | Exam practice programs, collected problem statements, solution documents, and additional generated practice variants. |
| [`Exercism/c/`](./Exercism/c) | C exercises completed through Exercism, including their Unity-based test suites. |
| [`BPE/`](./BPE) | Course presentation materials. |
| [`.vscode/`](./.vscode) | VS Code build, run, debug, and IntelliSense configuration for GCC/GDB on Windows. |

## Representative work

### Dynamic matrix processing

[`Laboratorni/Lab 6 - 7.04.26/task_4.c`](./Laboratorni/Lab%206%20-%207.04.26/task_4.c) dynamically allocates a square matrix, reads its elements, processes the main and secondary diagonals and the elements above and below the main diagonal, and then releases all allocated memory.

### Structured binary and text file storage

[`Laboratorni/Lab 9 - 20.04.26/task_3.c`](./Laboratorni/Lab%209%20-%2020.04.26/task_3.c) defines a `Car` structure and implements a menu-driven program that creates and appends records to both binary and formatted text files, then reads the two representations for comparison.

### Exam-style record management

[`Exams/exam_all.c`](./Exams/exam_all.c) combines dynamically allocated arrays of structures, string and date processing, record filtering, enrollment constraints, and binary and text file output in a course-and-student management exercise.

### Tested practice exercises

The [`Exercism/c/`](./Exercism/c) directory contains independently buildable exercises such as `difference-of-squares` and `grains`, together with headers, Makefiles, and Unity test files.

## Study resources

The repository also contains study notes created for review and exam preparation:

- [`study-plan-C-programming.md`](./study-plan-C-programming.md) — detailed Bulgarian-language guide covering the complete progression from basic syntax to structures and file processing.
- [`EXAM_STUDY_PLAN.md`](./EXAM_STUDY_PLAN.md) — condensed intensive revision schedule and topic checklist.
- [`QUICK_REFERENCE_CARD.md`](./QUICK_REFERENCE_CARD.md) — compact syntax and standard-library reference.
- [`SOLVED_EXAMPLES.md`](./SOLVED_EXAMPLES.md) — worked examples of recurring exercise patterns.

## Building and running an exercise

There is no single repository-wide executable. Compile the source file you want to run individually.

### Requirements

- A C17-compatible GCC installation
- Git
- Optional: VS Code with the Microsoft C/C++ extension and GDB

### Clone the repository

```bash
git clone https://github.com/veselinkalinov/university-c-labs.git
cd university-c-labs
```

### Compile with GCC

From the repository root, replace the example path with the desired source file:

```bash
gcc -std=c17 -Wall -Wextra -pedantic "Laboratorni/Lab 9 - 20.04.26/task_3.c" -o task_3
```

Run on Linux or macOS:

```bash
./task_3
```

Run on Windows:

```powershell
.\task_3.exe
```

Programs that read or write files normally create those files in the current working directory. Run them from their own exercise directory when relative file paths are important.

## VS Code workflow

The included VS Code tasks support the Windows GCC/GDB workflow used while completing the coursework:

- `Ctrl+Shift+B` builds the currently active C file.
- The **Run Active C File** task builds and executes it.
- The **Debug Active C File** launch configuration builds the active file and starts it with GDB.

The current configuration expects GCC, GDB, and an MSYS2/MinGW-style toolchain to be installed locally. Paths may need to be adjusted for another machine.

## Notes

- The source files preserve the development history of the coursework, including early introductory solutions and later exam-preparation programs. They are learning artifacts rather than production-ready software.
- Exercise descriptions and some comments are in Bulgarian because the coursework was completed at the Technical University of Sofia.
- Files and folders explicitly named `ClaudeGenerated` or `exam_claude_*` contain AI-generated or AI-assisted practice material. They are included as supplementary study resources and are not presented as official university assignments or solely authored solutions.
- This repository should be used as a learning reference. Anyone completing similar coursework should follow their institution's academic-integrity rules and write their own solutions.

## Author

**Veselin Kalinov**  
Computer and Software Engineering student, Technical University of Sofia

- GitHub: [veselinkalinov](https://github.com/veselinkalinov)
- LinkedIn: [veselinkalinov](https://www.linkedin.com/in/veselinkalinov/)
