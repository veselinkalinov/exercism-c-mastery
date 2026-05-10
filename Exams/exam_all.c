#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    unsigned long courseId;
    char courseName[129];
    char lecturerName[65];
    char startDate[11];
    int studentsInCourse;
}Course;

typedef struct
{
    char studentName[65];
    unsigned long fNum;
    int coursesNum;
    int coursesIds[11];
}Student;

int zad2(Course *courses, int courseNum, char *lecturerName, char *startDate, char *endDate)
{
    FILE *ft = fopen("course_info.txt", "w");
    if (ft == NULL){exit(1);}
    int allCourses = 0;

    int startDay,startMonth,startYear;
    sscanf(startDate, "%d.%d.%d", &startDay,&startMonth,&startYear);
    int start = startYear * 10000 + startMonth * 100 + startDay;

    int endDay, endMonth, endYear;
    sscanf(endDate, "%d.%d.%d", &endDay, &endMonth, &endYear);
    int end = endYear * 10000 + endMonth * 100 + endDay;

    for (int i = 0; i < courseNum; i++)
    {
      int curDay, curMonth, curYear;
      sscanf(courses[i].startDate, "%d.%d.%d", &curDay, &curMonth, &curYear);
      int cur = curYear * 10000 + curMonth * 100 + curDay;

      if (strcmp(courses[i].lecturerName,lecturerName) ==0 && cur >= start && cur <= end)
      {
        if(fprintf(ft, "%lu:%s:%s-%d\n", courses[i].courseId,courses[i].courseName,courses[i].startDate,courses[i].studentsInCourse) != 4){exit(1);}
        allCourses++;
      }
    }
    fclose(ft);
    if(allCourses == 0){return -1;}
    return allCourses;
}

int zad3(Course *courses, int courseNum, Student *students, int studentsNum, unsigned long fNum, unsigned long courseId)
{
    FILE *fb = fopen("course_student.bin", "ab");
    if (fb == NULL){return -1;}

    int courseIdx = -1;
    int studentIdx = -1;

    for (int i = 0; i < courseNum; i++)
    {
        if (courses[i].courseId == courseId)
        {
            courseIdx = i;
            break;
        }
    }

    for (int i = 0; i < studentsNum; i++)
    {
        if (students[i].fNum == fNum)
        {
            studentIdx = i;
            break;
        }
    }

    for (int i = 0; i < students[studentIdx].coursesNum; i++) {
      if (students[studentIdx].coursesIds[i] == courseId) {
        fclose(fb);
        return 0;
        break;
      }
    }

    if (courses[courseIdx].studentsInCourse >= 30)
        {
            fclose(fb);
            return 0;
        }

    if(students[studentIdx].coursesNum > 10)
    {
        fclose(fb);
        return 0;
    }

    courses[courseIdx].studentsInCourse ++;
    students[studentIdx].coursesIds[students[studentIdx].coursesNum] = courseId;
    students[studentIdx].coursesNum++;

    fwrite(&courseId, sizeof(unsigned long),1,fb);
    fwrite(&fNum,sizeof(unsigned long),1,fb);

    fclose(fb);
    return 1;
}

void zad4(Course *courses, int *courseNum, char *date) {
  int targetDay, targetMonth, targetYear;
  sscanf(date, "%d.%d.%d", &targetDay, &targetMonth, &targetYear);
  int target = targetYear * 10000 + targetMonth * 100 + targetDay;

  int counter = 0;
  int found = 0;
  for (int i = 0; i < *courseNum; i++) {
    int curDay, curMonth, curYear;
    sscanf(courses[i].startDate, "%d.%d.%d", &curDay, &curMonth, &curYear);
    int cur = curYear * 10000 + curMonth * 100 + curDay;

    if (cur >= target) {
      courses[counter] = courses[i];
      counter++;
    } else {
      found = 1;
    }
  }

  if (!found) {
    printf("No courses found before the given date.\n");
  }

  *courseNum = counter;
}

int main(void)
{
    int courseNum, studentsNum;
    printf("Courses Num: "); scanf("%d",&courseNum);
    printf("Students Num: "); scanf("%d", &studentsNum);

    Course *courses = NULL;
    courses = malloc(courseNum * sizeof(Course));
    if (courses == NULL){exit(1);}

    Student *students = NULL;
    students = malloc(studentsNum * sizeof(Student));
    if (students == NULL){exit(1);}

    for (int i = 0; i < courseNum; i++)
    {
        printf("Course ID: "); scanf("%lu", &courses[i].courseId);
        printf("Course Name: "); scanf(" %128[^\n]", courses[i].courseName);
        printf("Lecturer Name: "); scanf(" %64[^\n]", courses[i].lecturerName);
        printf("Start Date: "); scanf("%10s", courses[i].startDate);

        courses[i].studentsInCourse = 0;
    }

    for (int i = 0; i < studentsNum; i++)
    {
        printf("Student Name: "); scanf(" %64[^\n]",students[i].studentName);
        printf("Faculty Number: "); scanf("%lu",&students[i].fNum);

        students[i].coursesNum = 0;
        for (int j = 0; j < 11; j++)
        {
            students[i].coursesIds[j] = 0;
        }
    }

    free(students);
    free(courses);
    return 0;
}
