#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int asc(const void *a, const void *b) {
  return *(char *)a - *(char *)b;
}

int main() {
  char str[4];
  scanf("%s", str);
  qsort(str , 3, sizeof(char), asc);
  if(strcmp(str, "abc") == 0) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  return 0;
}
