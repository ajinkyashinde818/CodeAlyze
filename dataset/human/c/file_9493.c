#include<stdio.h>

int main(){
    int n, d, x;
    int A[110];
    int sum;

    scanf("%d %d %d", &n, &d, &x);
    for(int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }

    sum = x+n;
    for(int i=0; i<n; i++){
        sum += (d-1)/A[i];
    }

    printf("%d", sum);

    return 0;
}
