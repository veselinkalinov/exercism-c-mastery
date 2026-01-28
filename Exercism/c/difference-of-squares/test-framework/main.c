#include <stdio.h>
#include <assert.h>
#include "difference_of_squares.h"

void test_n_10(void)
{
    printf("Testing N = 10...\n");
    unsigned int sq_sum = square_of_sum(10);
    unsigned int sum_sq = sum_of_squares(10);
    unsigned int diff = difference_of_squares(10);

    printf("  Square of Sum: %u (Expected: 3025)\n", sq_sum);
    printf("  Sum of Squares: %u (Expected: 385)\n", sum_sq);
    printf("  Difference: %u (Expected: 2640)\n", diff);

    // Validating against the prompt's data
    assert(sq_sum == 3025);
    assert(sum_sq == 385);
    assert(diff == 2640);
    printf("  [PASS]\n\n");
}

void test_n_1(void)
{
    printf("Testing N = 1 (Edge Case)...\n");
    // (1)² = 1, 1² = 1, Diff = 0
    assert(difference_of_squares(1) == 0);
    printf("  Difference: %u\n  [PASS]\n\n", difference_of_squares(1));
}

void test_n_100(void)
{
    printf("Testing N = 100 (Larger Input)...\n");
    // Known values: SqSum = 25502500, SumSq = 338350
    unsigned int diff = difference_of_squares(100);
    printf("  Difference: %u\n  [PASS]\n\n", diff);
}

int main(void)
{
    test_n_10();
    test_n_1();
    test_n_100();

    printf("All tests passed successfully.\n");
    return 0;
}
