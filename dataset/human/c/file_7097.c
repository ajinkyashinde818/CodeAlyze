#include<stdio.h>
int main(void){
    int a,b,i,H,W;
    while(1){
        scanf("%d %d",&H,&W);
        if(H==0&&W==0)break;
        for(a=0;a<H;a++){
            for(b=0;b<W;b++){
                    i=a+b;
                    if(i%2==0){
                        printf("#");
                    }
                    else if(i%2==1){
                        printf(".");
                    }

            }
        printf("\n");
        }
        printf("\n");
    }
    return 0;
}
