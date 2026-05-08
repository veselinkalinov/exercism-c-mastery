# EXAM STUDY PLAN - ONE DAY INTENSIVE
## Complete Guide to Passing Your C Programming Exam

---

## 📊 YOUR COURSE OVERVIEW

### What You're Studying
- **3 Seminar Exercises**: 21 tasks total
  - Basics, I/O, control flow
  - Functions and algorithms
  - Arrays and strings
  
- **8 Laboratory Exercises**: ~45 tasks total
  - Progressive complexity
  - I/O → Functions → Arrays → Pointers → Structs

### Total Coverage
- **10 Core Topics** that appear across all exercises
- **50+ Solved Examples** in your study materials
- **Predictable Patterns** that repeat frequently

---

## ⏰ ONE-DAY STUDY SCHEDULE

### Timeline: 6 Hours Total (Can do 4-5 if experienced)

```
TIME         TOPIC                 ACTION                    CONFIDENCE CHECK
────────────────────────────────────────────────────────────────────────────
00:00-01:00  I/O & Variables       • Read theory              Can write printf/scanf?
             Format specifiers     • Study examples           Know all format specs?
             Data types            • Practice 3 exercises     
             
01:00-02:00  Control Flow          • Conditionals theory      Can write if/else?
             If/Else              • Logical operators        Know == vs =?
             Loops                • While & For loops         Can create loops?
             
02:00-03:00  Functions             • Function declaration     Can declare functions?
             Parameters           • Return values            Know scope rules?
             Return values        • Pass by value            Can call functions?
             
         *** 15 MINUTE BREAK ***  (Rest, water, stretch)
         
03:15-04:15  Arrays                • Declaration & access     Can work with arrays?
             Loops in arrays      • Common patterns          Know array indexing?
             2D arrays (if needed) • Practice 10 exercises    Can do nested loops?
             
04:15-05:15  Strings              • String operations       Can handle strings?
             Pointers            • Array of chars           Know strlen, strcpy?
             Memory              • Pointer basics           Understand & and *?
             
05:15-06:00  Review & Practice    • Solve mixed problems    Ready for exam?
             Problem solving     • Try difficult exercises  Can handle anything?
             Exam prep           • Review checklist
```

---

## 📚 DETAILED TOPIC BREAKDOWN

### Topic 1: Input/Output (45 minutes)
**Difficulty**: ⭐ EASY

**Must Know**:
```c
#include <stdio.h>
int main() {
    int x;
    double y;
    char c;
    
    scanf("%d", &x);      // Read integer
    scanf("%lf", &y);     // Read double
    scanf(" %c", &c);     // Read character (space before %c!)
    
    printf("%d\n", x);    // Print integer
    printf("%.2lf\n", y); // Print double with 2 decimals
    printf("%c\n", c);    // Print character
    
    return 0;
}
```

**Common Mistakes**:
- ❌ scanf("%d", x) - Missing &
- ❌ scanf("%s", &name) - & not needed for strings
- ❌ printf("value is %d" x); - Missing comma

**Exercises to Do**: Seminar 01 Tasks 1, 5, 10
**Time Needed**: 45 minutes

---

### Topic 2: Variables & Data Types (30 minutes)
**Difficulty**: ⭐ EASY

**Must Know**:
| Type | Size | Use | Example |
|------|------|-----|---------|
| int | 4 bytes | Whole numbers | age = 25 |
| double | 8 bytes | Decimals | salary = 50000.50 |
| char | 1 byte | Single char | letter = 'A' |
| float | 4 bytes | Decimals (less precise) | price = 9.99f |

**Key Rules**:
- Declare before use: `int age;`
- Initialize: `int age = 25;`
- Variables are case-sensitive: age ≠ Age

**Exercises to Do**: Lab 01 Tasks 1-3
**Time Needed**: 30 minutes

---

### Topic 3: Control Flow - Conditionals (45 minutes)
**Difficulty**: ⭐⭐ EASY-MEDIUM

**Critical Pattern**:
```c
if (condition) {
    // code if true
} else if (condition2) {
    // code if condition2 true
} else {
    // code if all false
}
```

**Operators Reference**:
```c
==  (equal)
!=  (not equal)
>   (greater)
<   (less)
>=  (greater or equal)
<=  (less or equal)
&&  (AND - both true)
||  (OR - one true)
!   (NOT - reverse)
```

**⚠️ CRITICAL**: Use `==` for comparison, `=` for assignment
```c
if (x == 5) { }     // Correct - compare
if (x = 5) { }      // WRONG - this assigns!
```

**Exercises to Do**: Seminar 02 Tasks 1-3, Lab 02 Tasks 1-2
**Time Needed**: 45 minutes

---

### Topic 4: Loops (60 minutes)
**Difficulty**: ⭐⭐ MEDIUM

**FOR Loop** (when you know count):
```c
for (int i = 0; i < 10; i++) {
    printf("%d ", i);  // Prints 0 1 2 3 4 5 6 7 8 9
}
```

**WHILE Loop** (when you don't know count):
```c
int num;
while (num != 0) {
    scanf("%d", &num);
    // Process num
}
```

**DO-WHILE** (runs at least once):
```c
do {
    scanf("%d", &num);
} while (num != 0);
```

**Common Patterns**:
```c
// Count down
for (int i = 10; i > 0; i--) { }

// Step by 2
for (int i = 0; i < 20; i += 2) { }

// Read until 0
int num;
scanf("%d", &num);
while (num != 0) {
    // process
    scanf("%d", &num);
}
```

**Exercises to Do**: Seminar 01 Tasks 3, 4, 6
**Time Needed**: 60 minutes

---

### Topic 5: Functions (60 minutes)
**Difficulty**: ⭐⭐ MEDIUM

**Basic Structure**:
```c
// Declaration (optional if defined before main)
int add(int a, int b);

// Definition
int add(int a, int b) {
    return a + b;
}

// Call
int result = add(5, 3);  // result = 8
```

**Return Types**:
```c
void greet(char *name) {
    printf("Hello %s\n", name);  // No return
}

int getSum(int a, int b) {
    return a + b;               // Returns int
}

double average(double x, double y) {
    return (x + y) / 2.0;       // Returns double
}
```

**Key Concept**: Variables inside functions are LOCAL
```c
int x = 10;        // Global
void test() {
    int x = 5;     // Local - different from global
    x++;           // Changes local x, not global
}
```

**Exercises to Do**: Seminar 02 All, Lab 02 All
**Time Needed**: 60 minutes

---

### Topic 6: Arrays (75 minutes)
**Difficulty**: ⭐⭐⭐ MEDIUM-HARD

**Declaration & Access**:
```c
int arr[5];          // Array of 5 integers (indices 0-4)
arr[0] = 10;         // First element
arr[4] = 50;         // Last element

// Initialize
int nums[] = {1, 2, 3, 4, 5};
```

**⚠️ CRITICAL**: 0-indexed!
```c
int arr[5];  // Indices: 0, 1, 2, 3, 4 (NOT 1-5)
arr[0] = 1;  // First element
arr[4] = 5;  // Last element
arr[5] = 6;  // OUT OF BOUNDS - ERROR!
```

**Reading Array**:
```c
int n;
scanf("%d", &n);
int arr[n];

for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);  // Use & with scanf!
}
```

**Common Operations**:
```c
// Find max
int max = arr[0];
for (int i = 1; i < n; i++) {
    if (arr[i] > max) max = arr[i];
}

// Find min
int min = arr[0];
for (int i = 1; i < n; i++) {
    if (arr[i] < min) min = arr[i];
}

// Sum all
int sum = 0;
for (int i = 0; i < n; i++) {
    sum += arr[i];
}

// Count condition
int count = 0;
for (int i = 0; i < n; i++) {
    if (arr[i] > 50) count++;
}
```

**Exercises to Do**: Seminar 03 All, Lab 03 All
**Time Needed**: 75 minutes

---

### Topic 7: Strings (60 minutes)
**Difficulty**: ⭐⭐⭐ MEDIUM-HARD

**String Basics**:
```c
#include <string.h>

char str[50];              // String variable
scanf("%s", str);          // Read string (NO & needed!)
printf("%s\n", str);       // Print string

int len = strlen(str);     // Get length
strcpy(dest, src);         // Copy string
```

**⚠️ CRITICAL STRING RULES**:
1. Strings end with '\0' (null terminator) automatically
2. Array size must be +1: `char str[51]` for 50 chars + null
3. NO & in scanf for strings: `scanf("%s", str);`
4. YES & in scanf for other types: `scanf("%d", &x);`

**Character Iteration**:
```c
char str[] = "hello";

// Print each character
for (int i = 0; str[i] != '\0'; i++) {
    printf("%c ", str[i]);  // Prints: h e l l o
}

// Reverse string
for (int i = strlen(str) - 1; i >= 0; i--) {
    printf("%c", str[i]);
}
```

**String Functions** (remember to include <string.h>):
```c
strlen(str)           // Length of string
strcpy(dest, src)     // Copy
strcmp(str1, str2)    // Compare (0 if equal)
strcat(str1, str2)    // Concatenate
```

**Exercises to Do**: Lab 03 Tasks with strings
**Time Needed**: 60 minutes

---

### Topic 8: Pointers (45 minutes)
**Difficulty**: ⭐⭐⭐ HARD

**Basic Concept**:
```c
int x = 10;
int *ptr = &x;           // ptr points to x

printf("%d\n", *ptr);    // Dereference: prints 10
printf("%p\n", (void*)ptr); // Print address (hex)

*ptr = 20;               // Change value through pointer
printf("%d\n", x);       // x is now 20!
```

**Key Symbols**:
- `&` = address-of operator (get address)
- `*` = dereference operator (get value at address)

**Function with Pointers** (modify original variable):
```c
void increment(int *num) {
    (*num)++;  // Increment value at address
}

int main() {
    int x = 5;
    increment(&x);  // Pass address
    printf("%d\n", x);  // Prints 6
    return 0;
}
```

**Array and Pointers**:
```c
int arr[5] = {1, 2, 3, 4, 5};
int *ptr = arr;      // Point to first element

printf("%d\n", *ptr);      // 1
printf("%d\n", *(ptr+1));  // 2

ptr++;  // Move to next
printf("%d\n", *ptr);      // 2
```

**Exercises to Do**: Lab 04 All
**Time Needed**: 45 minutes

---

### Topic 9: Structs (45 minutes)
**Difficulty**: ⭐⭐ MEDIUM

**Define and Use**:
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

**With Pointers** (use ARROW ->):
```c
struct Person p1;
struct Person *ptr = &p1;

ptr->age = 30;      // Use -> not .
printf("%d\n", ptr->age);
```

**Array of Structs**:
```c
struct Person people[3];

// Fill
for (int i = 0; i < 3; i++) {
    scanf("%s", people[i].name);
    scanf("%d", &people[i].age);
}

// Access
printf("%s\n", people[0].name);
```

**Key Rule**: 
- Use `.` for direct access: `p1.age`
- Use `->` for pointer access: `ptr->age`

**Exercises to Do**: Lab 05 All
**Time Needed**: 45 minutes

---

### Topic 10: Algorithm Patterns (30 minutes)
**Difficulty**: ⭐⭐⭐ HARD

These are the most commonly tested patterns:

**Pattern 1: Find Maximum**
```c
int max = arr[0];
for (int i = 1; i < n; i++) {
    if (arr[i] > max) {
        max = arr[i];
    }
}
```

**Pattern 2: Find Minimum**
```c
int min = arr[0];
for (int i = 1; i < n; i++) {
    if (arr[i] < min) {
        min = arr[i];
    }
}
```

**Pattern 3: Sum with Condition**
```c
int sum = 0;
for (int i = 0; i < n; i++) {
    if (arr[i] > 50) {
        sum += arr[i];
    }
}
```

**Pattern 4: Count Occurrences**
```c
int count = 0;
for (int i = 0; i < n; i++) {
    if (arr[i] == target) {
        count++;
    }
}
```

**Pattern 5: Check Property**
```c
bool isAscending = true;
for (int i = 0; i < n - 1; i++) {
    if (arr[i] > arr[i + 1]) {
        isAscending = false;
        break;
    }
}
```

**Pattern 6: Min and Max Together**
```c
int min = arr[0], max = arr[0];
for (int i = 1; i < n; i++) {
    if (arr[i] > max) max = arr[i];
    if (arr[i] < min) min = arr[i];
}
```

---

## ✅ COMPLETE CHECKLIST

Before you go to the exam, make sure you can:

### Basics
- [ ] Write a program from scratch with main()
- [ ] Include necessary headers (#include)
- [ ] Declare and initialize variables
- [ ] Use printf and scanf correctly
- [ ] Know all format specifiers

### Control Flow
- [ ] Write if/else conditions
- [ ] Use comparison operators correctly (==, !=, >, <, >=, <=)
- [ ] Use logical operators (&&, ||, !)
- [ ] Avoid = vs == confusion

### Loops
- [ ] Write for loops (with correct initialization, condition, increment)
- [ ] Write while loops
- [ ] Break out of loops with break
- [ ] Skip iterations with continue

### Functions
- [ ] Declare function prototypes
- [ ] Define functions with proper return types
- [ ] Call functions with correct parameters
- [ ] Return values properly
- [ ] Understand variable scope

### Arrays
- [ ] Declare arrays correctly
- [ ] Access array elements with 0-indexing
- [ ] Read arrays with loops
- [ ] Find max, min, sum
- [ ] Count elements meeting conditions

### Strings
- [ ] Read strings without &
- [ ] Use strlen, strcpy, strcmp
- [ ] Iterate through string characters
- [ ] Remember null terminator

### Pointers
- [ ] Understand & (address) and * (dereference)
- [ ] Create pointers
- [ ] Use pointers in function parameters
- [ ] Modify variables through pointers

### Structs
- [ ] Define struct types
- [ ] Create struct instances
- [ ] Access fields with . and ->
- [ ] Work with arrays of structs

### Problem Solving
- [ ] Read requirements carefully
- [ ] Plan solution before coding
- [ ] Write pseudocode first
- [ ] Test with multiple inputs
- [ ] Check edge cases

---

## 🎯 HOW TO STUDY EFFICIENTLY

### DON'T:
- ❌ Just read code
- ❌ Copy-paste solutions
- ❌ Skip exercises
- ❌ Only read hard examples

### DO:
- ✅ Type code yourself
- ✅ Compile and run each program
- ✅ Modify examples to understand them
- ✅ Solve exercises from scratch
- ✅ Test with different inputs
- ✅ Debug when something breaks

---

## 📖 STUDY MATERIALS YOU HAVE

1. **C_Programming_Study_Guide.md** - Complete theory with examples
2. **QUICK_REFERENCE_CARD.md** - Print this for exam day!
3. **SOLVED_EXAMPLES.md** - Real examples from your course
4. **This document** - Your study plan and checklist

---

## 🚀 READY FOR THE EXAM?

### Before Exam Day
1. Study using this plan (4-6 hours)
2. Solve at least 30 exercises from your course
3. Print the quick reference card
4. Get good sleep the night before
5. Have a good breakfast/lunch before exam

### During Exam
1. Read the problem carefully twice
2. Plan your solution first
3. Write code step by step
4. Test your code if you can
5. Review for silly mistakes (= vs ==, & usage)
6. Don't panic if one problem is hard - move on and come back

### The Most Important Tips
- **Start with what you know** - Basic I/O first
- **Build incrementally** - Get part working, then add more
- **Test frequently** - Don't write 50 lines then compile
- **Remember patterns** - The exercises repeat patterns
- **Use the quick reference** - It has everything you need

---

## 💪 YOU CAN DO THIS!

You have:
- ✅ Complete theory guide
- ✅ Quick reference card
- ✅ Solved examples
- ✅ Study schedule
- ✅ 45+ exercises to practice

The exam tests the same patterns repeatedly. Master them and you'll pass!

**Good luck! 🎓💻**
