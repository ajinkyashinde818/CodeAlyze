#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int x, y;

  scanf("%x %x", &x, &y);
  if (x > y) {
    printf(">");
    }
  else if (x == y) {
      printf("=");
    }
  else {
    printf("<");
  }
  printf("\n");
}
