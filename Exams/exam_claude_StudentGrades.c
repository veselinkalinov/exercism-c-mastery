#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[40];
    int id;
    char subject[30];
    float grade;
}Grade;

Grade *addGrade(Grade *arr, int *count)
{
    (*count)++;
    arr = realloc(arr, (*count)*sizeof(Grade));
    if (arr == NULL)
    {
        exit(1);
    }

    Grade *g = &arr[(*count)-1];
    scanf("%39s\n%d\n%29s\n%f", g->name, &g->id, g->subject, &g->grade);

    FILE *ft = fopen("grades.txt", "a");
    if (ft == NULL) {exit(1);}

    fprintf(ft, "%s;%d;%s;%.2f", g->name,g->id,g->subject,g->grade);

    fclose(ft);
    return arr;
}

int findFailingStudents(Grade *arr, int count)
{
    int n = 0;
    printf("Failing students:\n");
    for (int i = 0; i < count; i++)
    {
        if (arr[i].grade < 3)
        {
            n++;
            printf("%s - %d - %s - %.2f\n", arr[i].name,arr[i].id,arr[i].subject,arr[i].grade);
        }
    }

    printf("Count: %d\n", n);
    if(n == 0)
    {
        printf("No failing students.\n");
    }

    return n;
}

void saveGradesBin(Grade *arr, int count)
{
    FILE *fb = fopen("grades.bin", "wb");
    if (fb == NULL)
    {
        exit(1);
    }

    fwrite(arr, sizeof(Grade), count, fb);

    fclose(fb);
}

void savePassingStudents(float minGrade)
{
    FILE *fb = fopen("grades.bin", "rb");
    if (fb == NULL) {exit(1);}

    FILE *ft = fopen("grades.txt", "w");
    if (ft == NULL) {exit(1);}

    Grade g;
    while(fread(&g,sizeof(Grade),1,fb)==1)
    {
        if (g.grade >= minGrade)
        {
            printf("Binary Pass: %s|%s|%.2f\n", g.name,g.subject,g.grade);
            fprintf(ft, "%s;%s;%.2f\n", g.name,g.subject,g.grade);
        }
    }

    fclose(fb);
    fclose(ft);

    ft = fopen("grades.txt", "r");
    if (ft == NULL){exit(1);}

    while (fscanf(ft, "%s;%s;%f", g.name, g.subject,&g.grade)==3)
    {
      printf("Text pass: %s;%s;%.2f\n", g.name, g.subject,g.grade);
    }

      fclose(ft);
}

int main(void)
{
    Grade *arr = NULL;
    int count = 0;

    arr = addGrade(arr, &count);
    arr = addGrade(arr, &count);
    arr = addGrade(arr, &count);

    findFailingStudents(arr, count);

    saveGradesBin(arr, count);
    savePassingStudents(3.00);

    free(arr);
    return 0;
}
