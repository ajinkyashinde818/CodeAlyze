#include <stdio.h>
#include <stdlib.h>

int main()
{
    int H,W,i,j;
    while(1){
        scanf("%d %d",&H,&W);
        if(H == 0){
            if(W == 0){
                break;
            }
        }
        for(i = 1;i <= H;i++){
            if(i % 2 == 1){
                for(j = 1;j <= W;j++){
                    if(j % 2 == 1){
                        printf("#");
                    }else{
                        printf(".");
                    }
                }
                printf("\n");
            }else{
                for(j = 1;j <= W;j++){
                    if(j % 2 == 1){
                        printf(".");
                    }else{
                        printf("#");
                    }
                }
                printf("\n");
            }
        }
        printf("\n");
    }
    return 0;
}
