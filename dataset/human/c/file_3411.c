#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
//  char *buf=(char*)malloc(sizeof(char) * 20000);
char buf[100100];

scanf("%[^\n]", buf);
char* cur = buf;
int length = strlen(buf);

char l1[] = "dream";
char l2[] = "dreamer";
char l3[] = "erase";
char l4[] = "eraser";
int a1 = 5;
int a2 = 7;
int a3 = 5;
int a4 = 6;

while (length > 0) {
  if (strstr(cur, l4) == cur) {
    length -= a4;
    if (length <= 0) {
      break;
    }
    cur = cur + a4;
  } else if (strstr(cur, l3) == cur) {
    length -= a3;
    if (length <= 0) {
      break;
    }
    cur = cur + a3;
  } else if (strstr(cur, "dreamerase") == cur) {
    length -= a1;
    if (length <= 0) {
      break;
    }
    cur = cur + a1;
  } else if (strstr(cur, l2) == cur) {
    length -= a2;
    if (length <= 0) {
      break;
    }
    cur = cur + a2;
  } else if (strstr(cur, l1) == cur) {
    length -= a1;
    if (length <= 0) {
      break;
    }
    cur = cur + a1;
  } else {
    break;
  }
  }

  if (length == 0) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }

  return 0;
}
