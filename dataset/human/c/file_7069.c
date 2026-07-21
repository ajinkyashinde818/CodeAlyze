#include<stdio.h>
int main(void)
{
    int H,W,i,j;
    for(;;){
        scanf("%d %d",&H,&W);
        if(H==0 && W==0){
            return 0;
        }
        for(i=0;i<H;i++){
            for(j=0;j<W;j++){
                if((j+i)%2==0){
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
