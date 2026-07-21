#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    
    while (1) {
        int h,w;
        scanf("%d %d",&h,&w);
        
        if(h == 0 && w == 0){
            break;
        }
        
        
        int i,j;
        for(i=0;i<h;i++){
            for(j=0;j<w;j++){
                if((i%2 == 0 && j%2 ==0) ||
                   (i%2 == 1 && j%2 ==1)){
                    printf("#");
                }
                else{
                    printf(".");
                }
            }
            printf("\n");
        }
        
        printf("\n");
    }
    return 0;
}
