#include <stdio.h>
int main(void) {
   int i, j;
   int h, w;
   while(1) { 
      scanf("%d %d", &h, &w);
      if(h==0 && w==0) break;
      for(i=1; i<=h; i++) {
         for(j=1; j<=w; j++) {
            if((i%2==1 && j%2==1) || (i%2==0 && j%2==0))
               putchar('#');
            else
               putchar('.');
         }
         putchar('\n');
      }
      putchar('\n');
   }
   return (0);
}
