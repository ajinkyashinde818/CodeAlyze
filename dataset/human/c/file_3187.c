#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int K, N, i, a, max;

    scanf("%d %d", &K, &N);
    int A[N];
    for(i=0; i<N; i++) {
        scanf("%d",&A[i]);
    }
    max = abs(K-A[N-1]);

    if(A[0] == 0) {
        max = K - A[N-1];         
    } else {
        max = K - A[N-1]  + A[0];
    }

    for(i=1; i<N; i++) {
        a = A[i-1];
        if(max < abs(a - A[i])){
            max = abs(a - A[i]);
        }
    }

    printf("%d\n", K-max);


    return 0;
}
