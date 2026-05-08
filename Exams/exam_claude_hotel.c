#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[40];
    char id[7];
    char date[11];
    float price;
}Reservation;

Reservation *addReservation(Reservation *arr, int *count)
{
    (*count)++;
    arr = realloc(arr, (*count) * sizeof(Reservation));
    if (arr == NULL)
    {
        exit(1);
    }

    Reservation *r = &arr[(*count)-1];
    printf("Name: "); scanf(" %39[^\n]",r->name);
    printf("ID: "); scanf("%6s", r->id);
    printf("Date: "); scanf("%10s", r->date);
    printf("Price: "); scanf("%f", &r->price);

    FILE *ft = fopen("reservations.txt", "a");
    if (ft == NULL)
    {
        exit(1);
    }

    fprintf(ft, "%s;%s;%s;%.2f", r->name, r->id, r->date, r->price);

    fclose(ft);
    return arr;
}

Reservation *filterExpensive(Reservation *arr, int count, float limit, Reservation *result, int *newCount)
{
    for (int i = 0; i < count; i++)
    {
        if (arr[i].price>limit)
        {
            (*newCount)++;
            result = realloc(result, (*newCount) * sizeof(Reservation));
            if (result == NULL)
            {
                exit(1);
            }
            result[(*newCount)-1] = arr[i];
        }
    }

    return result;
}

void convertReservationsTxt()
{
    FILE *fb = fopen("binFile.bin", "rb");
    if (fb == NULL)
    {
        exit(1);
    }
    FILE *ft = fopen("txtFile.txt", "w");
    if (ft == NULL) {
      exit(1);
    }

    Reservation r;
    while(fread(&r, sizeof(Reservation),1,fb)==1)
    {
        printf("Binary: %s|%s|%.2f", r.name, r.id, r.price);
        fprintf(ft, "%s;%s;%.2f", r.name, r.id, r.price);

    }

    fclose(fb);
    fclose(ft);

    ft = fopen("txtFile.txt", "r");
    if (ft == NULL) {
      exit(1);
    }

    Reservation rt;
    fscanf(ft, "%s;%s;%f", rt.name, rt.id, &rt.price);
    printf("Text: %s;%s;%.2f", rt.name, rt.id, rt.price);

    fclose(ft);
}

int main(void)
{
    Reservation *arr = NULL;
    int count = 0;

    arr = addReservation(arr, &count);
    arr = addReservation(arr, &count);
    arr = addReservation(arr, &count);

    Reservation *result = NULL;
    int newCount = 0;
    result = filterExpensive(arr, count, 100.00, result, &newCount);
    for (int i = 0; i < count; i++)
    {
        printf("%s - %s - %s - %.2f", result[i].name, result[i].id, result[i].date, result[i].price);
    }

    FILE *fb = fopen("binFile.bin", "wb");
    if (fb == NULL)
    {
        exit(1);
    }

    fwrite(arr, sizeof(Reservation),count,fb);
    convertReservationsTxt();

    fclose(fb);
    free(arr);
    free(result);
    return 0;
}
