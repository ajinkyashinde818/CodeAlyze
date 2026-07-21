#include<stdio.h>
int main(){
    int h,w,i,j;
    while(1){
        scanf("%d %d",&h,&w);
        if(h==0&&w==0)return 0;
        for(i=1;i<=h;i++){
            for(j=1;j<=w;j++){
                if(i%2==j%2)printf("#");
                else printf(".");
                }
                printf("\n");
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
