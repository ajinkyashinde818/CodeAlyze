#include <stdio.h>

int main (void) {
    int h, w, i, j;
    
    while (1) {
        scanf("%d%d", &h, &w);
        
         if(h == w && h == 0)
             break;

         for(i=0; i < h; i++) {
             for(j=0; j < w; j++) {
                 if((i + j) % 2 == 0)
                     putchar('#');
                 else
                     putchar('.');
             }
             putchar('\n');
         }
         putchar('\n');
    }
    return 0;
}
