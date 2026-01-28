#include "grains.h"
#include <stdio.h>
main()
{
    unsigned int n;

    printf("Square Num: ");
    scanf("%u", &n);

    printf("\nResults %u squares:\n", n);
    printf("\nThe number of grains on a given square: %u\n", square(n));
    printf("\nThe total number of grains on the chessboard: %u\n", total(n));
}
