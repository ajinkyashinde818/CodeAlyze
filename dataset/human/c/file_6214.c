#include<stdio.h>

int main(){
    int i;
    
    //input
    int n;
    scanf("%d", &n);
    
    int R[n];
    for( i = 0; i < n; i++)
        scanf("%d", &R[i]);
    
    int max = R[1] - R[0];
    int min = R[0];
    
    for ( i = 1; i < n; i++){
        max = max < R[i] - min ? R[i] -min : max;
        min = min > R[i] ? R[i] : min;
    }
    printf("%d\n", max);
    
    return 0;
}
