#include <stdio.h>

int main()
{
    int a, b, i, j;
    for(;;){
        scanf("%d %d", &a, &b);
        if( a >= 1 && b <= 300){
            for(i = 0 ; i < a ; i ++){
                for(j = 0 ; j < b ; j ++){
                    if(i % 2 == 1 && j % 2 == 1){
                        printf("#");
                    }
                    else if(i % 2 == 0 && j % 2 == 0){
                        printf("#");
                    }
                    else{
                        printf(".");
                    }
                }
                printf("\n");
            }
        }
        if(a == 0 && b == 0){
            break;
        }
        printf("\n");
    }
    return 0;
}
