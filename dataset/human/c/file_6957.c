#include <stdio.h>
#include <math.h>
 
int main(void)
{
    int h, w;
     
    while (scanf("%d %d", &h, &w) * h){
        int i, j;
         
        for (i = 0; i < h; i++){
            for (j = 0; j < w; j++){
                if ((i+j)%2==0){
                    putchar('#');
                }
                else {
                    putchar('.');
                }
            }
            puts("");
        }
        puts("");
    }
     
    return 0;
}
