#include <stdio.h>

void FuncPrintChessboard(int H, int W)
{
  int i,j;

  for (i = 0; i < H; i++) {
    for (j = 0; j < W; j++) {
      if (i % 2 == 0) {
	if (j % 2 == 0) {
	  printf("#");
	} else {
	  printf(".");
	}
      } else {
	if (j % 2 == 0) {
	  printf(".");
	} else {
	  printf("#");
	}
      }
    }
    putchar('\n');
  }
}

int main(void)
{
  int h,w;

  while(1){
    scanf("%d %d", &h, &w);
    if (h == 0 && w == 0) break;
    FuncPrintChessboard(h, w);
    putchar('\n');
  }

  return 0;
}
