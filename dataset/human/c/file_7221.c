#include <stdio.h>
int main(void)

{
  int H, W, i, j, k;

  scanf("%d %d", &H, &W);

  for (k=1; ;k++) {
     if ((H == 0) && (W == 0)) {
       break;
      }
     for (i=0; i<H; i++) {
        for (j=0; j<W; j++) {
           if (i % 2 == 0) {
             if (j % 2  == 0) {
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
           printf("\n");
         }
     printf("\n");
     scanf("%d %d", &H, &W);  
    }
  return 0;
}
