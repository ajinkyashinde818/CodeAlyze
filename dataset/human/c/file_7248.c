#include <stdio.h>

int main(void){
    int h,w;
    int i,j;
    while(scanf("%d %d",&h,&w)!=EOF && (h!=0 || w!=0)){
        for(i=0;i<h;i++){
            for(j=0;j<w;j++){
                if((i%2==0 && j%2==0) || (i%2==1 && j%2==1))printf("#");
                if((i%2==1 && j%2==0) || (i%2==0 && j%2==1))printf(".");
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
