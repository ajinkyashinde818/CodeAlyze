#include <stdio.h>
#define swap(a, b) ((a != b) && (a += b, b = a - b, a -= b))

int main(void)
{
  int h, w, i, j;

  while (scanf("%d %d", &h, &w), h || w) {
    for (i = 0; i < h; i++) {
      for (j = 0; j < w; j++) {
        if ((j+i)%2 == 0)
          printf("#");
        else
          printf(".");
      }
      printf("\n");
    }
    printf("\n");
  }


  return 0;
}
