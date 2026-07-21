// Maximum profit
#include<stdio.h>

int max(int a, int b){
    return (a > b) ? a : b;
}

int min(int a, int b){
    return (a < b) ? a : b;
}

int main(void){
    int n;
    int i;
    int R, minv, maxv;

    scanf("%d", &n);
    
    scanf("%d", &minv);
    scanf("%d", &R);
    maxv = R - minv;
    minv = min(minv ,R);

    for(i = 2; i < n; i++){
        scanf("%d", &R);
        maxv = max(maxv, R - minv);
        minv = min(minv, R);
    }

    printf("%d\n", maxv);

    return 0;
}
