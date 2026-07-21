#include<stdio.h>
int main(void){
    int H,W,i,j;
    while(H != 0 || W != 0){
    scanf("%d %d",&H ,&W);
    for(i=0; i<H; i++){
        if(i==0 || i%2==0){
            printf("#");
        for(j=1; j<W; j++){
            if(j%2==0){
            printf("#");
            }
            else{
                printf(".");
            }
        }
        printf("\n");
        }
        else{
            printf(".");
            for(j=2; j<W+1; j++){
                if(j%2!=0){
                    printf(".");
                }
                else{
                    printf("#");
                }
            }
            printf("\n");
        }
    }
        if(H != 0 || W !=0){
        printf("\n");
        }
    }
    return 0;
}
