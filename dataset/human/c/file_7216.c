#include <stdio.h>

int main(){
    int i,j;
    int H, W;
    
    while(1){
        scanf("%d %d",&H, &W);
        for(i = 0; i < H; i++){
            if (i % 2== 0) {
                for(j = 0; j < W - 1; j++){
                    if (j % 2 ==0) {
                        printf("#");
                    }
                    else{
                        printf(".");
                    }
                }
                if(W % 2 == 1){
                    printf("#\n");
                }
                else{
                    printf(".\n");
                }
            }
            else{
                for(j = 0; j < W - 1; j++){
                    if (j % 2 == 0) {
                        printf(".");
                    }
                    else{
                        printf("#");
                    }
                }
                if(W % 2 == 1){
                    printf(".\n");
                }
                else{
                    printf("#\n");
                }
                
            }
        }
        if(H == 0 && W == 0){
            break;
        }
        printf("\n");
    }
    return (0);
}
