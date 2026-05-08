#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    unsigned long long int id;
    char course[129];
    char cname[65];
    char date[11];
    int students;
}Course;

typedef struct
{
    char name[65];
    unsigned long long int id;
    int courseCount;
    unsigned long long *course_ids;
}Student;

Course *addCourse(Course *arr, int *count)
{
    (*count)++;
    arr = realloc(arr, (*count)*sizeof(Course));
    if (arr==NULL)
    {
        exit(1);
    }

    Course *c = &arr[(*count)-1];

    printf("ID: "); scanf("%llu", &c->id);
    printf("Course: "); scanf("%128s", c->course);
    printf("Name: "); scanf(" %64[^\n]", c->cname);
    printf("Date: "); scanf("%10s", c->date);
    printf("Students number: "); scanf("%d", &c->students);

    return arr;
}

Student *addStudent(Student *arr, int *n)
{
    (*n)++;
    arr = realloc(arr, (*n)*sizeof(Student));
    if (arr == NULL)
    {
        exit(1);
    }

    Student *s = &arr[(*n)-1];
    printf("ID: "); scanf("%llu", &s->id);
    printf("Course count: "); scanf("%d", &s->courseCount);
    printf("Name: "); scanf(" %64[^\n]", s->name);

    s->course_ids = malloc(s->courseCount * sizeof(unsigned long long));

    if (s->course_ids == NULL) {
      exit(1);
    }

    for (int i = 0; i < s->courseCount; i++) {
      s->course_ids[i] = 0;
    }

    return arr;
}

int zad2(Course *arr, int count, char *cname, char *startDate, char *endDate)
{
    FILE *ft = fopen("course_info.txt", "w");
    if (ft == NULL)
    {
        return -1;
    }

    int match_Count = 0;
    int d1, m1, y1, d2, m2, y2;
    sscanf(startDate, "%d.%d.%d", &d1, &m1, &y1);
    sscanf(endDate, "%d.%d.%d", &d2, &m2, &y2);

    for (int i = 0; i < count; i++)
    {
        int targetDay, targetMonth, targetYear;
        sscanf(arr[i].date, "%d.%d.%d", &targetDay, &targetMonth, &targetYear);

        if (strcmp(arr[i].cname, cname) == 0)
        {
            int inPeriod = 0;

            if (targetYear > y1 && targetYear < y2) {
                inPeriod = 1;
            } else if (targetYear == y1 && targetMonth > m1) {
                inPeriod = 1;
            } else if (targetYear == y1 && targetMonth == m1 && targetDay >= d1) {
                inPeriod = 1;
            }
            if (targetYear == y2 && targetMonth < m2) {
                inPeriod = 1;
            } else if (targetYear == y2 && targetMonth == m2 && targetDay <= d2) {
                inPeriod = 1;
            }

            if (inPeriod)
            {
                match_Count++;
                fprintf(ft, "%llu:%s:%s-%d\n", arr[i].id, arr[i].course, arr[i].date, arr[i].students);
            }
        }
    }

    fclose(ft);
    if (match_Count != 0) {
        return match_Count;
    } else {
        return -1;
    }
}
