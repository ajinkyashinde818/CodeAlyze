#include <stdio.h>

int main(void) {
    long long N, K, x, a, b, c, k, l, X, A[200005], B[200005], C[200005], i;
    scanf("%lld%lld", &N, &K);
    for (i=0; i<N; i++) {
        scanf("%lld", &A[i]);
        A[i]--;
    }
    for (i=0; i<N; i++) B[i]=-1;
    x=0; B[0]=0; C[0]=x; i=0;
    a=0; b=0;
    while (1) {
        i++;
        x=A[x];
        C[i]=x;
        if (i==K) {
            c=0;
            break;
        }
        if (B[x]!=-1) {
            a=B[x];
            b=i;
            c=1;
            break;
        }
        B[x]=i;
        // printf("%lld %lld\n", i, x);
    }
    if (c) {
        k=K-a;
        l=b-a;
        X=a+k%l;
        // printf("[%lld, %lld]", a, b);
        // printf("[%lld, %lld, %lld]", k, l, X);
        printf("%lld", C[X]+1);
    }
    else printf("%lld", x+1);
    return 0;
}
