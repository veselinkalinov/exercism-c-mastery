# C Programming QUICK REFERENCE CARD
## Print this for exam day! ⏱️

---

## BASIC STRUCTURE
```c
#include <stdio.h>

int main() {
    // Your code here
    return 0;
}
```

---

## PRINTF / SCANF QUICK TABLE

| Task | Code |
|------|------|
| Print integer | `printf("%d\n", x);` |
| Print double | `printf("%.2lf\n", x);` |
| Print string | `printf("%s\n", name);` |
| Read integer | `scanf("%d", &x);` |
| Read double | `scanf("%lf", &x);` |
| Read string | `scanf("%s", name);` |
| Read char | `scanf(" %c", &c);` |

---

## DATA TYPES CHEAT SHEET

| Type | Format | Example | Range |
|------|--------|---------|-------|
| int | %d | 42 | -2B to +2B |
| double | %lf | 3.14 | decimals |
| char | %c | 'A' | -128 to 127 |
| float | %f | 2.5 | decimals |

---

## OPERATORS QUICK REFERENCE

### Arithmetic
- `+` addition
- `-` subtraction
- `*` multiplication
- `/` division
- `%` modulo (remainder)

### Comparison
- `==` equal
- `!=` not equal
- `>` greater
- `<` less
- `>=` greater or equal
- `<=` less or equal

### Logical
- `&&` AND (both true)
- `||` OR (one true)
- `!` NOT (reverse)

### Assignment
- `=` assign
- `+=` add and assign (x += 5 means x = x + 5)
- `-=` subtract and assign
- `*=` multiply and assign
- `++` increment by 1
- `--` decrement by 1

---

## LOOPS - COPY & PASTE

### FOR Loop
```c
for (int i = 0; i < 10; i++) {
    printf("%d\n", i);
}
```

### WHILE Loop
```c
int num;
while (num != 0) {
    scanf("%d", &num);
}
```

### DO-WHILE Loop
```c
do {
    scanf("%d", &num);
} while (num != 0);
```

---

## IF/ELSE - COPY & PASTE

### Simple If
```c
if (age >= 18) {
    printf("Adult\n");
}
```

### If-Else
```c
if (age >= 18) {
    printf("Adult\n");
} else {
    printf("Minor\n");
}
```

### If-Else If-Else
```c
if (age >= 18) {
    printf("Adult\n");
} else if (age >= 13) {
    printf("Teen\n");
} else {
    printf("Child\n");
}
```

---

## FUNCTIONS - COPY & PASTE

### Function that Returns a Value
```c
int add(int a, int b) {
    return a + b;
}

int main() {
    int result = add(5, 3);  // result = 8
    printf("%d\n", result);
    return 0;
}
```

### Function that Returns Nothing (void)
```c
void printGreeting(char *name) {
    printf("Hello, %s!\n", name);
}

int main() {
    printGreeting("John");
    return 0;
}
```

---

## ARRAYS - COPY & PASTE

### Declare and Use
```c
int arr[5];  // Array of 5 integers
arr[0] = 10; // First element
arr[4] = 50; // Last element

// Loop through
for (int i = 0; i < 5; i++) {
    printf("%d\n", arr[i]);
}
```

### Read Array from Input
```c
int n;
scanf("%d", &n);
int arr[n];

for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
}
```

---

## STRINGS - COPY & PASTE

### Basic String Operations
```c
#include <string.h>

char name[50];
scanf("%s", name);  // NO & needed!

printf("%s\n", name);           // Print string
int len = strlen(name);         // Get length
strcpy(copy, name);             // Copy string
if (strcmp(str1, str2) == 0) {  // Compare strings
    printf("Equal\n");
}
```

### Loop Through String
```c
char str[50];
scanf("%s", str);

// Print each character
for (int i = 0; str[i] != '\0'; i++) {
    printf("%c", str[i]);
}
```

---

## POINTERS - COPY & PASTE

### Basic Pointer
```c
int x = 10;
int *ptr = &x;  // ptr points to x

printf("%d\n", *ptr);  // Print value: 10
printf("%p\n", (void*)ptr);  // Print address
```

### Function with Pointer (Modify Original)
```c
void increment(int *num) {
    (*num)++;
}

int main() {
    int x = 5;
    increment(&x);
    printf("%d\n", x);  // Prints 6
    return 0;
}
```

---

## STRUCTS - COPY & PASTE

### Define and Use
```c
struct Person {
    char name[50];
    int age;
    double salary;
};

int main() {
    struct Person p1;
    
    // Access with DOT (.)
    p1.age = 30;
    strcpy(p1.name, "John");
    
    printf("%s is %d\n", p1.name, p1.age);
    return 0;
}
```

### With Pointer (Use ARROW ->)
```c
struct Person *ptr = &p1;
printf("%d\n", ptr->age);  // Use -> not .
```

---

## COMMON ALGORITHM TEMPLATES

### Find Maximum
```c
int max = arr[0];
for (int i = 1; i < n; i++) {
    if (arr[i] > max) max = arr[i];
}
```

### Find Minimum
```c
int min = arr[0];
for (int i = 1; i < n; i++) {
    if (arr[i] < min) min = arr[i];
}
```

### Sum All Elements
```c
int sum = 0;
for (int i = 0; i < n; i++) {
    sum += arr[i];
}
```

### Count Occurrences
```c
int count = 0;
for (int i = 0; i < n; i++) {
    if (arr[i] == value) count++;
}
```

---

## 🚨 CRITICAL ERRORS TO AVOID

| ❌ WRONG | ✅ CORRECT | WHY |
|---------|-----------|-----|
| `if (x = 5)` | `if (x == 5)` | Use == for comparison, = for assignment |
| `scanf("%d", x)` | `scanf("%d", &x)` | Use & for variables in scanf |
| `scanf("%s", &name)` | `scanf("%s", name)` | NO & for strings in scanf |
| `int arr[5]; arr[5]` | `arr[0]` through `arr[4]` | Array indices 0 to size-1 |
| `void add(a, b) { return a+b; }` | `int add(int a, int b)` | Specify parameter types & return type |
| `int x = ptr;` | `int x = *ptr;` | Use * to dereference pointer |
| `char str[10];` | `char str[11];` | Size+1 for null terminator |
| `len = sizeof(str);` | `len = strlen(str);` | strlen() for string length |
| `.age` with pointer | `->age` with pointer | Use -> for pointer access |

---

## 📌 MUST REMEMBER

✅ Always include: `#include <stdio.h>`

✅ Always have: `int main() { return 0; }`

✅ Variable declaration: `type name;`

✅ Array declaration: `type arr[size];`

✅ String declaration: `char str[51];` (if max 50 chars)

✅ Function declaration before main or define before use

✅ Loops need: initialization, condition, increment/decrement

✅ If statements compare with ==, not =

✅ scanf needs & for variables: `scanf("%d", &x);`

✅ scanf doesn't need & for strings: `scanf("%s", name);`

✅ Arrays and strings are 0-indexed

✅ Strings end with '\0' automatically

✅ Pointers: & gets address, * gets value

✅ Structs with . for direct, -> for pointers

---

## 🔧 TESTING YOUR CODE

### Compile (gcc)
```bash
gcc program.c -o program
./program
```

### Common Issues
- **Compilation error**: Check syntax (missing semicolons, parentheses)
- **Wrong output**: Check logic (conditions, loops)
- **Crashes**: Check array bounds, pointer dereference
- **Hangs**: Infinite loop (check loop condition)

---

## EXAM DAY STRATEGY

1. **Read the problem carefully** - Understand what's needed
2. **Plan before coding** - Write pseudocode or outline
3. **Start with basic I/O** - printf/scanf first
4. **Test with examples** - Use simple test cases
5. **Build incrementally** - Get one part working, then add more
6. **Check edge cases** - Test with 0, negative, large numbers
7. **Review syntax** - Use this card to verify
8. **Don't panic** - If stuck, move on and come back

---

**YOU'VE GOT THIS! 💪** Study hard, code confidently!
