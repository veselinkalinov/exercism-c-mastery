#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[35];
    char id[9];
    int quantity;
    float price;
}Item;

Item *addItem(Item *arr, int *count)
{
    (*count)++;
}
