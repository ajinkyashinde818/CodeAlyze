#include <stdio.h>

int main( void ){
    int n, x, i, min, maxv;

    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &x);
        if(i == 0){
            min = x;
        }
        else if(i == 1){
            maxv = x - min;
            if(x < min){
                min = x;
            }
        }
        else{
            if(maxv < x - min){
                maxv = x - min;
            }
            if(x < min){
                min = x;
            }
        }
    }
    printf("%d\n", maxv);
    return 0;
}
