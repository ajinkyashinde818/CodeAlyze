#include <stdio.h>
#include <string.h>

int main(void) {

  char s[50];
  scanf("%s", s);

  int i;
  for (i = 0; i < 50; i++) {
        if (s[i] == '\0') {
          break;
        }
  }

  int j;
  for (j = 0; j <= i - 9; j++) {
        printf("%c", s[j]);
  }
  printf("\n");

  return 0;
}
