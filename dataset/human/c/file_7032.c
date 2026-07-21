#include <stdio.h>
int main(void)
{
    int H ,W;
    int i, j;
    while(1){
        scanf("%d %d" ,&H ,&W);
        if(H == 0 && W == 0) break;
        for ( i = 1; i <= H; i++ ){
            for ( j = 1; j <= W; j++ ){
                if((i%2==1&&j%2==1)||(i%2==0&&j%2==0)){
                    printf("#");
                }else{
                    printf(".");
                }
            }
            printf("\n");
        }
        puts("");
    }
    return 0;
}
