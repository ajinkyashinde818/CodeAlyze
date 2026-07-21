#include<stdio.h>

int main(){
    int i,n;

    scanf("%d", &n);
    
    int R[n];

    for(i=0;i<n;i++){
        scanf("%d", &R[i]);
    }
    
    int maxv = R[1] - R[0];
    int minv = R[0];

    for(i=1; i<n; i++){
        maxv = maxv < R[i] - minv ? R[i] - minv : maxv;
        minv = minv > R[i] ? R[i] : minv;
    }

    printf("%d\n", maxv);

    return 0;
}
