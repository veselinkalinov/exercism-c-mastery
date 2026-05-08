#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[31];
    char date[8];
    unsigned long long int id;
    float price;
    int quantity;
}Medicine;

Medicine *zad2(Medicine *arr, int count, char *date)
{
    int targetMonth, targetYear;
    sscanf(date, "%d.%d", &targetMonth, &targetYear);

    Medicine *result = NULL;
    int n = 0;

    for (int i = 0; i < count; i++)
    {
        int curMonth,curYear;
        sscanf(arr[i].date, "%d.%d", &curMonth, &curYear);

        if (targetYear > curYear || (curYear == targetYear && curMonth < targetMonth))
        {
            n++;
            result = realloc(result, n*sizeof(Medicine));
            if (result == NULL)
            {
                exit(1);
            }

            result[n-1] = arr[i];
        }
    }
    if (n>0){return result;}
    else {return NULL;}
}

int zad3(Medicine *arr, int count, float maxPrice, float minPrice)
{
    FILE *ft = fopen("offer.txt", "w");
    if (ft == NULL)
    {
        exit(1);
    }

    int count_el = 0;

    for (int i = 0; i < count; i++)
    {
        if (arr[i].price >= minPrice && arr[i].price <= maxPrice)
        {
            count_el++;
            fprintf(ft, "%s\n%s\n%llu\n%.2fleva\n\n",arr[i].name, arr[i].date, arr[i].id, arr[i].price);
        }
    }

    fclose(ft);
    return count_el;
}

void zad4(Medicine *arr, int *count, char *date, char *name)
{
    int idx = -1;
    for (int i = 0; i < *count; i++)
    {
        if (strcmp(arr[i].date,date)==0 && strcmp(arr[i].name,name)==1)
        {
            idx = i;
        }
    }

    for (int i = idx; i < *count - 1; i++){
        arr[i] = arr[i+1];
    }

    (*count)--;
    arr = realloc(arr, (*count) * sizeof(Medicine));
    if (arr == NULL)
    {
        exit(1);
    }

    if (idx == -1)
    {
        printf("No such medicine.");
    }
}

int main(void)
{
    Medicine *medicines = NULL;
    int count = 0;

    FILE *fb = fopen("medicines.bin", "rb");
    if (fb == NULL)
    {
        exit(1);
    }

    Medicine temp;
    while(fread(&temp, sizeof(Medicine),1,fb)==1)
    {
        count++;
        medicines = realloc(medicines, count * sizeof(Medicine));
        if (medicines == NULL)
        {
            exit(1);
        }

        medicines[count - 1] = temp;
    }

    fclose(fb);
    free(medicines);
    return 0;
}
