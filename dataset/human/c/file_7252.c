#include<stdio.h>
int main(void){
    int h,w,i,j;
    scanf("%d%d",&h,&w);
    while(h!=0 || w!=0){
        for(i=1; i<=h; i++){
            for(j=1; j<=w; j++){
                if((i%2)==(j%2)){
                    printf("#");
                }else{
                    printf(".");
                }
            }
            printf("\n");
        }
        printf("\n");
        scanf("%d%d",&h,&w);
    }
    return 0;
}
