#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strnum(char* s1, char* s2) {
  int i = 0;
  while (1) {
    if (*(s1+i) == *(s2+i)) {
      i++;
    } else {
      break;
    }
  }
  return i;
}

int main() {
  char* buff = (char*)malloc(sizeof(char) * 100001);
  scanf("%s", buff);
  while (strcmp(buff, "\0") != 0 && strcmp(buff, "\n") != 0) {
    char* sd = "dreameraseX";
    int num = strnum(buff, sd);
    if (num == 5 || num == 10) {
      buff += 5;
      continue;
    } else if (num == 7) {
      buff += 7;
      continue;
    }
    char* se = "eraseraseX";
    num = strnum(buff, se);
    if (num == 5 || num == 9) {
      buff += 5;
      continue;
    } else if (num == 6) {
      buff += 6;
      continue;
    }
    printf("NO\n");
    return 0;
  }
  printf("YES\n");
  return 0;
}
