#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
  int i, j;

  char str[60];

  scanf("%[^\n]%*c", str);

  int n = strlen(str);
  n -= 8;
  for (i = 0; i < n; i++) {
    printf("%c", str[i]);
  }
  return 0;
}
