#include <stdio.h>
int main(void){
    int i = 0;
    int a[i+100],b[i+100];
    while(1){
        scanf("%d %d",&a[i],&b[i]);
        if(a[i] == 0 && b[i] == 0){
            break;
        }
        i = i + 1;
    }
    int j, H ,W;
    for(j = 0;j < i;j++){
        for(H = 0;H < a[j];H++){
            for(W = 0;W < b[j];W++){
                if((H + W) % 2 == 0){
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
