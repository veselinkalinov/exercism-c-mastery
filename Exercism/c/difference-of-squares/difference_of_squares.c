#include <stdio.h>
#include "difference_of_squares.h"
int main()
{
    unsigned int n;

    printf("--- Difference of Squares Calculator ---\n");
    printf("Enter a natural number (N): ");

    if (scanf("%u", &n) != 1)
    {
        printf("Error: Please enter a valid positive integer.\n");
        return 1;
    }

    unsigned long long sq_sum = square_of_sum(n);
    unsigned long long sum_sq = sum_of_squares(n);
    unsigned long long diff = difference_of_squares(n);

    printf("\nResults for N = %u:\n", n);
    printf("1. Square of the sum (1 + ... + %u)^2:   %llu\n", n, sq_sum);
    printf("2. Sum of the squares (1^2 + ... + %u^2): %llu\n", n, sum_sq);
    printf("3. The difference (1 - 2):                %llu\n", diff);

    return 0;
}

unsigned long long square_of_sum(unsigned int number)
{
    unsigned long long n = number;
    unsigned long long sum = (n * (n + 1)) / 2;
    return sum * sum;
}

unsigned long long sum_of_squares(unsigned int number)
{
    unsigned long long n = number;
    return (n * (n + 1) * (2 * n + 1)) / 6;
}

unsigned long long difference_of_squares(unsigned int number)
{
    return square_of_sum(number) - sum_of_squares(number);
}
