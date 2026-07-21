#include <stdio.h>
int main(void){
    int h[100],w[100],i = 0;
    while(1){
        scanf("%d %d",&h[i],&w[i]);
        if(h[i] == 0 && w[i] == 0){
            break;
        }
        i = i + 1;
    }
    int j = i,H,W;
    for(i = 0;i < j;i++){
        for(H = 0;H < h[i];H++){
            for(W = 0;W < w[i];W++){
                if((H+W)%2 == 0){
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
