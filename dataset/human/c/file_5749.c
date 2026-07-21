#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);

    int R[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &R[i]);
    }

    int minv = R[0];
    int max_gap = R[1] - R[0];

    for(int i = 1; i < n; i++){
        if(max_gap < R[i] - minv){
            max_gap = R[i] - minv;
        }
        if(R[i] < minv){
            minv = R[i];
        }
    }

    printf("%d\n", max_gap);

    return 0;
}
