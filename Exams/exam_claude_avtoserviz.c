#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char owner[30];
    char plate[9];
    char date[11];
    float price;
}Order;

Order *addOrder(Order *arr, int *count)
{
    (*count)++;
    arr = realloc(arr,(*count)*sizeof(Order));
    if (arr == NULL)
    {
        exit(1);
    }

    Order *o = &arr[(*count)-1];
    printf("Owner: "); scanf("%29s", o->owner);
    printf("Plate: "); scanf("%8s", o->plate);
    printf("Date: "); scanf("%10s", o->date);
    printf("Price: "); scanf("%f", &o->price);

    FILE *ft = fopen("orders.txt", "a");
    if (ft == NULL)
    {
        exit(1);
    }

    fprintf(ft, "%d;%s;%s;%s;%.2f",(int)strlen(o->owner),o->owner,o->plate,o->date,o->price);

    fclose(ft);
    return arr;
}

void averageAndPrint(Order *arr, int count)
{
    float sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += arr[i].price;
    }

    float avg = sum/count;
    printf("Avg: %.2f\n", avg);

    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (arr[i].price > avg)
        {
            found = 1;
            printf("Above average:\n");
            printf("%s - %s - %.2f\n", arr[i].owner,arr[i].plate,arr[i].price);
        }
    }

    if (!found)
    {
        printf("All arr[i].price are under or equal to the avg price");
    }
}

void saveOrdersBin(Order *arr, int count)
{
    FILE *fb = fopen("orders.bin", "wb");
    if (fb == NULL)
    {
        exit(1);
    }

    fwrite(arr, sizeof(Order),count,fb);

    fclose(fb);
}

void searchOrdersByDate(char *searchDate)
{
    FILE *fb = fopen("orders.bin", "rb");
    if (fb == NULL)
    {
        exit(1);
    }

    int found = 0;
    Order o;
    while(fread(&o, sizeof(Order),1,fb)==1)
    {
        if (strcmp(o.date,searchDate)==0)
        {
            found = 1;
            printf("Bin Owner: %s\n", o.owner);
            printf("Bin Plate: %s\n", o.plate);
            printf("Bin Date: %s\n", o.date);
            printf("Bin Price: %.2f\n", o.price);
            printf("---\n");
        }
    }

    if(!found)
    {
        printf("No orders for date: <%s>", searchDate);
    }

    fclose(fb);
}

int main(void)
{
    Order *arr = NULL;
    int count = 0;

    arr = addOrder(arr, &count);
    arr = addOrder(arr, &count);
    arr = addOrder(arr, &count);

    averageAndPrint(arr, count);

    saveOrdersBin(arr, count);
    char *date = {"15.03.2026"};
    searchOrdersByDate(date);

    free(arr);
    return 0;
}
