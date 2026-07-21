#include <stdio.h>

int main()
{
  int H, W, i, j;

  while(scanf("%d %d", &H, &W) != EOF)
  {
    if(H == 0 && W == 0)
      break;

    for(i=0; i<H; i++)
    {
      for(j=0; j<W; j++)
      {
        if((i%2 == 0 && j%2 == 0) || (i%2 == 1 && j%2 == 1))
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
