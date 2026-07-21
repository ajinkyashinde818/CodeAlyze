#include <stdio.h>

int main(int argc, const char * argv[]){
    
    int i, j;
    int x, y;
    
    while (1) {
        scanf("%d %d", &x, &y);
        if (x==0 && y==0) {
            break;
        }else if(x<=300 && 1<=y){
            for ( i = 0; i < x; i++ ){
                for ( j = 0; j < y; j++ ){
                    if((i+j)%2==0){
                        printf("#");
                    }else if((i+j)%2==1){
                        printf(".");
                    }
                }printf("\n");
            }printf("\n");
        }
    }
    
    return 0;
}
