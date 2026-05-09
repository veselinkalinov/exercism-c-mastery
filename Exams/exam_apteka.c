#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[31];
  char date[8];
  unsigned long long int id;
  float price;
  int quantity;
} Medicine;

void zad2(Medicine *arr, int count, char *date) {
  int targetMonth, targetYear;
  sscanf(date, "%d.%d", &targetMonth, &targetYear);

  float oldPrice;
  int found = 0;

  for (int i = 0; i < count; i++) {
    int curMonth, curYear;
    sscanf(arr[i].date, "%d.%d", &curMonth, &curYear);

    if (curYear < targetYear ||
        (curYear == targetYear && curMonth < targetMonth)) {
      found = 1;
      oldPrice = arr[i].price;
      arr[i].price *= 0.8;
      printf("**************************\n");
      printf("%s - %s - %.2fleva - %.2fleva\n", arr[i].name, arr[i].date,
             oldPrice, arr[i].price);
    }
  }
  if (!found) {
    printf("No such medicine");
  }
}

void zad3(Medicine *arr, int count, int qty) {
  FILE *fb = fopen("offer.bin", "wb");
  if (fb == NULL) {
    exit(1);
  }

  for (int i = 0; i < count; i++) {
    if (arr[i].quantity > qty) {
      int nameLen = strlen(arr[i].name);
      fwrite(&nameLen, sizeof(int), 1, fb);
      fwrite(arr[i].name, sizeof(char), nameLen, fb);
      fwrite(arr[i].date, sizeof(char), 7, fb);
      fwrite(&arr[i].id, sizeof(unsigned long long int), 1, fb);
      fwrite(&arr[i].price, sizeof(float), 1, fb);
      fwrite(&arr[i].quantity, sizeof(int), 1, fb);
    }
  }

  fclose(fb);
}

void zad4(Medicine *arr, int *count, unsigned long long int id) {
  int idx = -1;
  for (int i = 0; i < *count; i++) {
    if (arr[i].id == id) {
      idx = i;
    }
  }

  if (idx == -1) {
    printf("No such medicine id");
    return;
  }

  for (int i = idx; i < *count - 1; i++) {
    arr[i] = arr[i + 1];
  }

  (*count)--;
  arr = realloc(arr, (*count) * sizeof(Medicine));
  if (arr == NULL) {
    exit(1);
  }
}

int main(void) {
  FILE *ft = fopen("medicines.txt", "r");
  if (ft == NULL) {
    exit(1);
  };

  Medicine *medicines = NULL;
  Medicine temp;
  int count = 0;

  while (fscanf(ft, "%30s;%7s;%llu;%f;%d", temp.name, temp.date, &temp.id,
                &temp.price, &temp.quantity) == 5) {
    count++;
    medicines = realloc(medicines, count * sizeof(Medicine));
    if (medicines == NULL) {
      exit(1);
    }

    medicines[count - 1] = temp;
  }

  free(medicines);
  fclose(ft);
  return 0;
}
