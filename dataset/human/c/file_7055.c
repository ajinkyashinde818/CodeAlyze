#include <stdio.h>
int main(void){
int i,j,d,w,h;
    for(i=0;i>=0;i++){
    scanf("%d %d", &h, &w);
    if (w==0 && h==0) 
break;
        for ( i = 0; i < h; i++ ){ 
               for ( j = 0; j < w; j++ ){ 
                   d=(i+j) % 2;
                    if (d==1) {
                    printf("."); 
                   }else{
                    printf("#"); 
                   }
                }
        printf("\n");
        }
    printf("\n");
    }
return 0;
}
