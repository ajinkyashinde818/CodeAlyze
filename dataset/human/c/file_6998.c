#include <stdio.h>

struct rectangle {
  int h, w;
};

int main(void) 
{
  int i, j;
  struct rectangle a;

  while (1) {
    scanf("%d %d", &a.h, &a.w);

    if (a.h == 0 && a.w == 0) 
      break;

    for (i = 0; i < a.h; i++) {
      for (j = 0; j < a.w; j++) {
	if (i % 2 == j % 2) 
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
