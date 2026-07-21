#include<stdio.h>

int main(void){
    int H, W;
    int i, j;

    while(1){
        scanf("%d %d", &H, &W);
        if(H == 0 && W == 0) return 0;

        for(i = 0; i < H; i++){
            if(i % 2 == 0){
                if(W % 2 == 0){
                    for(j = 0; j < W / 2; j++){
                        printf("#.");
                    }
                    printf("\n");
                }else{
                    for(j = 0; j < (W - 1) / 2; j++){
                        printf("#.");
                    }
                    printf("#");
                    printf("\n");
                }
            }else{
                if(W % 2 == 0){
                    for(j = 0; j < W / 2; j++){
                        printf(".#");
                    }
                    printf("\n");
                }else{
                    for(j = 0; j < (W - 1) / 2; j++){
                        printf(".#");
                    }
                    printf(".");
                    printf("\n");
                }
            }
        }
        printf("\n");
    }
}
