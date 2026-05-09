#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int id;
  char date[11];
  char name[31];
  char diagnosis[51];
} Treatment;

int count_treatment(Treatment *arr, int n, char *name, char *diagnosis) {
  int found = 0;
  for (int i = 0; i < n; i++) {
    if (strcmp(arr[i].name, name) == 0 &&
        strcmp(arr[i].diagnosis, diagnosis) == 0) {
      found++;
    }
  }

  return found;
}

Treatment *add_new_Treatment(Treatment *arr, int *n) {
  (*n)++;
  arr = realloc(arr, (*n) * sizeof(Treatment));
  if (arr == NULL) {
    return NULL;
  }

  Treatment *t = &arr[(*n) - 1];
  printf("Name: ");
  scanf("%30s", t->name);
  printf("ID: ");
  scanf("%d", &t->id);
  printf("Date: ");
  scanf("%10s", t->date);
  printf("Diagnosis: ");
  scanf("%50s", t->diagnosis);

  return arr;
}

int write_text_file(Treatment *arr, int n, char *diagnosis) {
  int count = 0;
  FILE *ft = fopen("illness.txt", "a");
  if (ft == NULL) {
    exit(1);
  }

  for (int i = 0; i < n; i++) {
    if (strcmp(arr[i].diagnosis, diagnosis) == 0) {
      count++;
      fprintf(ft, "Hospital stay of %s for treatment of %s:\n%s\n\n",
              arr[i].name, arr[i].diagnosis, arr[i].date);
    }
  }

  fclose(ft);
  return count;
}

int main(void) {
  Treatment *history = NULL;
  int n = 0;

  FILE *fb = fopen("history.bin", "rb");
  if (fb == NULL) {
    exit(1);
  }

  fread(&n, sizeof(int), 1, fb);

  history = malloc(n * sizeof(Treatment));
  if (history == NULL) {
    exit(1);
  }
  fread(history, sizeof(Treatment), n, fb);

  history = add_new_Treatment(history, &n);

  fclose(fb);
  free(history);
  return 0;
}
