#include <stdio.h>
#include <string.h>

int asc(const void *a, const void *b) {
  return *(char *)a - *(char *)b;
}

int desc(const void *a, const void *b) {
  return *(char *)b - *(char *)a;
}

int main() {
  char str_a[101], str_b[101];
  scanf("%s", str_a);
  scanf("%s", str_b);
  qsort(str_a, strlen(str_a), sizeof(char), asc);
  qsort(str_b, strlen(str_b), sizeof(char), desc);
  if(strcmp(str_a, str_b) < 0) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  return 0;
}
