#include<stdio.h>
int main(void){
    int i,j,h,w;
    while(scanf("%d %d",&h,&w),h!=0 && w!=0){
        for(i=1;i<=h;i++){
            if(i%2==1){
                for(j=1;j<=w;j++){
                    if(j%2==1)printf("#");
                    else  printf(".");
                }
            }
            else{
                for(j=1;j<=w;j++){
                    if(j%2==1)printf(".");
                    else printf("#");
                }

            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
