# SOLVED EXERCISE EXAMPLES
## Based on Your Repository

---

## SEMINAR EXERCISE 01 - EXAMPLES

### Task 1: Read and Print in Rectangle Pattern
**Problem**: Read a symbol and print it in a rectangle pattern

**Solution**:
```c
#include <stdio.h>

int main() {
    char symbol;
    
    printf("Enter a symbol: ");
    scanf("%c", &symbol);
    
    // Top border
    printf("%c%c%c%c%c%c%c%c%c%c\n", 
           symbol, symbol, symbol, symbol, symbol,
           symbol, symbol, symbol, symbol, symbol);
    
    // Middle (3 rows)
    printf("%c        %c\n", symbol, symbol);
    printf("%c        %c\n", symbol, symbol);
    printf("%c        %c\n", symbol, symbol);
    
    // Bottom border
    printf("%c%c%c%c%c%c%c%c%c%c\n",
           symbol, symbol, symbol, symbol, symbol,
           symbol, symbol, symbol, symbol, symbol);
    
    return 0;
}
```

**Output** (if symbol = '*'):
```
**********
*        *
*        *
*        *
**********
```

---

### Task 5: Currency Conversion
**Problem**: Convert BGN to dollars, euros, pounds

**Solution**:
```c
#include <stdio.h>

int main() {
    double bgn;
    
    printf("Enter money (BGN): ");
    scanf("%lf", &bgn);
    
    // Conversion rates
    double dollars = bgn * 0.60;
    double euros = bgn * 0.511292;
    double pounds = bgn * 0.45;
    
    // Print with 4 decimal places
    printf("Dollars: %.4lf\n", dollars);
    printf("Euros: %.4lf\n", euros);
    printf("Pounds: %.4lf\n", pounds);
    
    return 0;
}
```

**Example**:
- Input: 100
- Output:
  ```
  Dollars: 60.0000
  Euros: 51.1292
  Pounds: 45.0000
  ```

---

## SEMINAR EXERCISE 02 - EXAMPLES

### Task 1: Find Min and Max from Input Stream
**Problem**: Read numbers (terminated by 0) and find min/max

**Solution**:
```c
#include <stdio.h>

int findMaxNum(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int findMinNum(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

int main() {
    int num;
    scanf("%d", &num);
    
    int maxNum = num;
    int minNum = num;
    
    while (num != 0) {
        maxNum = findMaxNum(maxNum, num);
        minNum = findMinNum(minNum, num);
        
        scanf("%d", &num);
    }
    
    printf("Max num is: %d\n", maxNum);
    printf("Min num is: %d\n", minNum);
    
    return 0;
}
```

**Example**:
- Input: 5 10 3 8 0
- Output:
  ```
  Max num is: 10
  Min num is: 3
  ```

**KEY INSIGHT**: Using helper functions makes code cleaner and reusable!

---

### Task 5: Convert Seconds to Minutes:Seconds
**Problem**: Read total seconds, convert to MM:SS format

**Solution**:
```c
#include <stdio.h>

int main() {
    int a, b, c;
    
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    
    int sum = a + b + c;  // Total seconds
    
    int minutes = sum / 60;    // Integer division
    int seconds = sum % 60;    // Remainder
    
    printf("%d:%02d\n", minutes, seconds);  // %02d = pad with 0
    
    return 0;
}
```

**Example**:
- Input: 45 30 15 (three numbers representing seconds)
- Calculation: 45 + 30 + 15 = 90 seconds
- Output: `1:30` (1 minute 30 seconds)

---

## SEMINAR EXERCISE 03 - ARRAY EXAMPLES

### Task 2: Check Zigzag Pattern
**Problem**: Array should alternate: small, large, small, large...

**Solution**:
```c
#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    
    printf("Enter length of arr: ");
    scanf("%d", &n);
    
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        printf("Enter a number: ");
        scanf("%d", &arr[i]);
    }
    
    bool correct = true;
    
    for (int i = 1; i < n - 1; i++) {  // Check middle elements
        if (i % 2 == 0) {  // Even index = should be local min
            if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
                // Correct - it's smaller than neighbors
            } else {
                correct = false;
                break;
            }
        } else {  // Odd index = should be local max
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                // Correct - it's larger than neighbors
            } else {
                correct = false;
                break;
            }
        }
    }
    
    if (correct) {
        printf("Yes, it's a zigzag\n");
    } else {
        printf("No, it's not a zigzag\n");
    }
    
    return 0;
}
```

**Examples**:
- Input: [1, 5, 2, 8, 3] → YES (zigzag pattern)
- Input: [1, 2, 3, 4, 5] → NO (ascending, not zigzag)

---

## LABORATORY EXERCISE 01 - BASIC I/O

### Task: Read Different Data Types
**Problem**: Read int, double, char and print them

**Solution**:
```c
#include <stdio.h>

int main() {
    int a;
    double b;
    char c;
    
    printf("a = ");
    scanf("%d", &a);
    printf("%d\n", a);
    
    printf("b = ");
    scanf("%lf", &b);
    printf("%lf\n", b);
    
    printf("c = ");
    scanf(" %c", &c);  // Space before %c to skip whitespace
    printf("%c\n", c);
    
    return 0;
}
```

**Example**:
```
a = 42
42
b = 3.14
3.140000
c = X
X
```

---

## LABORATORY EXERCISE 02 - FUNCTIONS

### Task: Calculate Sum and Product
**Problem**: Create functions to find sum and product of two numbers

**Solution**:
```c
#include <stdio.h>

int calculateSum(int a, int b) {
    return a + b;
}

int calculateProduct(int a, int b) {
    return a * b;
}

int main() {
    int x, y;
    
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);
    
    int sum = calculateSum(x, y);
    int product = calculateProduct(x, y);
    
    printf("Sum: %d\n", sum);
    printf("Product: %d\n", product);
    
    return 0;
}
```

**Example**:
- Input: 5 3
- Output:
  ```
  Sum: 8
  Product: 15
  ```

---

## LABORATORY EXERCISE 03 - ARRAYS

### Task: Find Max Element and Its Index
**Problem**: Find largest number in array and its position

**Solution**:
```c
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int max = arr[0];
    int maxIndex = 0;
    
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
            maxIndex = i;
        }
    }
    
    printf("Max: %d at index %d\n", max, maxIndex);
    
    return 0;
}
```

**Example**:
- Input: 5 / 3 7 2 9 1
- Output: `Max: 9 at index 3`

---

## LABORATORY EXERCISE 04 - POINTERS

### Task: Swap Using Pointers
**Problem**: Create function that swaps two numbers using pointers

**Solution**:
```c
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;   // Store value at address a
    *a = *b;         // Put value at address b into a
    *b = temp;       // Put stored value into b
}

int main() {
    int x = 5;
    int y = 10;
    
    printf("Before: x = %d, y = %d\n", x, y);
    
    swap(&x, &y);  // Pass addresses
    
    printf("After: x = %d, y = %d\n", x, y);
    
    return 0;
}
```

**Output**:
```
Before: x = 5, y = 10
After: x = 10, y = 5
```

**KEY INSIGHT**: Pointers allow functions to modify original variables!

---

## LABORATORY EXERCISE 05 - STRUCTS

### Task: Store and Display Person Data
**Problem**: Create struct for person with name, age, salary

**Solution**:
```c
#include <stdio.h>
#include <string.h>

struct Person {
    char name[50];
    int age;
    double salary;
};

int main() {
    struct Person p1;
    
    printf("Enter name: ");
    scanf("%s", p1.name);
    
    printf("Enter age: ");
    scanf("%d", &p1.age);
    
    printf("Enter salary: ");
    scanf("%lf", &p1.salary);
    
    // Display
    printf("\n--- Person Info ---\n");
    printf("Name: %s\n", p1.name);
    printf("Age: %d\n", p1.age);
    printf("Salary: %.2lf\n", p1.salary);
    
    return 0;
}
```

**Example**:
```
Enter name: John
Enter age: 30
Enter salary: 50000.50

--- Person Info ---
Name: John
Age: 30
Salary: 50000.50
```

---

## ALGORITHM PATTERNS APPLIED

### Pattern: Find Even Numbers Sum
```c
int sum = 0;
for (int i = 0; i < n; i++) {
    if (arr[i] % 2 == 0) {  // Even number
        sum += arr[i];
    }
}
printf("Sum of even: %d\n", sum);
```

### Pattern: Count Numbers in Range
```c
int count = 0;
for (int i = 0; i < n; i++) {
    if (arr[i] >= 10 && arr[i] <= 20) {
        count++;
    }
}
printf("Numbers in range [10-20]: %d\n", count);
```

### Pattern: Check if Sorted
```c
bool isSorted = true;
for (int i = 0; i < n - 1; i++) {
    if (arr[i] > arr[i + 1]) {
        isSorted = false;
        break;
    }
}
printf("Sorted: %s\n", isSorted ? "Yes" : "No");
```

---

## HOW TO USE THESE EXAMPLES

1. **Read carefully**: Understand what the code does
2. **Type it out**: Don't copy-paste, type to learn
3. **Compile and run**: gcc example.c -o example; ./example
4. **Modify it**: Change numbers, conditions, try variants
5. **Solve your exercises**: Use patterns as templates

---

**Remember**: The exercises in your course follow these exact patterns!
Master these examples and you'll handle the exam!
