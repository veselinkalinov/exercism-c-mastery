#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[31];
  char id[8];
  float price;
} Patient;

Patient *zad1() {
  Patient *arr = NULL;
  int count = 0;
  int *pcount = &count;
  (*pcount)++;
  arr = realloc(arr, (*pcount) * sizeof(Patient));
  if (arr == NULL) {
    exit(1);
  }

  Patient *p = &arr[(*pcount) - 1];
  printf("Name: ");
  scanf("%30s", p->name);
  printf("ID: ");
  scanf("%7s", p->id);
  printf("Price: ");
  scanf("%f", &p->price);

  FILE *ft = fopen("animalsText.txt", "a");
  if (ft == NULL) {
    exit(1);
  }

  if (fprintf(ft, "%s,%.2f", p->name, p->price) < 0) {
    exit(1);
  }

  fclose(ft);
  return arr;
}

void zad2(Patient *arr, int count, float price) {
  int found = 0;
  for (int i = 0; i < count; i++) {
    if (arr[i].price == price) {
      found = 1;
      printf("%s - %s", arr[i].name, arr[i].id);
      break;
    }
  }
  if (!found) {
    printf("No such patient");
  }
}

void zad3(float price) {
  FILE *fb = fopen("animalsBin.bin", "rb");
  if (fb == NULL) {
    exit(1);
  }

  Patient p;
  while (fread(&p, sizeof(Patient), 1, fb) == 1) {
    if (p.price >= price) {
      printf("Bin OwnerName: %s\n", p.name);
      printf("Bin Chip: %s\n", p.id);
      printf("Bin Price: %.2f\n", p.price);
      printf("-------------------------\n");
    }
  }

  fclose(fb);
}

int main(void) {
  Patient *patients = NULL;

  patients = zad1();

  free(patients);
  return 0;
}
