#include<stdio.h>
int main(){
    int max = -2000000000, data[200000] = {};
    int n, i, r, min;
    scanf("%d", &n);
    for( i = 0; i < n; i++ ){
        scanf("%d", &data[i]);
    }
    min = data[0];
    max = data[1] - data[0];
    for( r = 1; r < n; r++ ){
        if( data[r] - min > max ){
            max = data[r] - min;
        }
        if( data[r] < min ){
           min = data[r];
        }
    }
    printf("%d\n", max);
    return 0;
}
