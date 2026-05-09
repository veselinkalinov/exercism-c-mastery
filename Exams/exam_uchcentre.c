#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[51];
  char date[11];
  int lectures;
  float price;
} Course;

void zad2(Course *arr, int n, int idx) {
  if (idx < 0 || idx > (n - 1)) {
    exit(1);
  }
  for (int i = 0; i < n; i++) {
    if (i == idx) {
      arr[i].price *= 0.9;
      printf("%.2f - %s - %s\n", arr[i].price, arr[i].name, arr[i].date);
      break;
    }
  }
}

int zad3(Course *arr, int n, float minPrice, float maxPrice) {
  FILE *ft = fopen("offer.txt", "w");
  if (ft == NULL) {
    exit(1);
  }
  int count = 0;

  for (int i = 0; i < n; i++) {
    if (arr[i].price >= minPrice && arr[i].price <= maxPrice) {
      count++;
      if (fprintf(ft, "%s\n%s\n%d lectures\n%.2flv.\n\n", arr[i].name,
                  arr[i].date, arr[i].lectures, arr[i].price) != 4) {
        exit(1);
      }
    }
  }

  fclose(ft);
  return count;
}

Course *zad4(Course *arr, int *n, char *name, char *date) {
  int idx = -1;
  for (int i = 0; i < *n; i++) {
    if (strcmp(arr[i].name, name) == 0 && strcmp(arr[i].date, date) == 0) {
      idx = i;
      break;
    }
  }

  if (idx == -1) {
    return NULL;
  }

  for (int i = idx; i < (*n) - 1; i++) {
    arr[i] = arr[i + 1];
  }

  (*n)--;
  arr = realloc(arr, (*n) * sizeof(Course));
  if (arr == NULL) {
    exit(1);
  }

  return arr;
}

int main(void) {
  Course *courses = NULL;
  int n = 0;

  FILE *fb = fopen("courses.bin", "rb");
  if (fb == NULL) {
    exit(1);
  }

  if (fread(&n, sizeof(int), 1, fb) != 1) {
    fclose(fb);
    exit(1);
  }

  courses = malloc(n * sizeof(Course));
  if (courses == NULL) {
    exit(1);
  }

  if (fread(courses, sizeof(Course), n, fb) != n) {
    fclose(fb);
    free(courses);
    exit(1);
  }

  fclose(fb);
  free(courses);
  return 0;
}
