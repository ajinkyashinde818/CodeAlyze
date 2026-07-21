#include <stdio.h>

long long gcd(long long A, long long B) {
    long long t, r;
    if (A<B) {
        t=A;
        A=B;
        B=t;
    }
    r = A%B;
    while (r!=0) {
        A=B;
        B=r;
        r=A%B;
    }
    return B;
}
int main(void) {
    long long A, B;
    scanf("%lld%lld", &A, &B);
    printf("%lld", A*B/gcd(A, B));
    return 0;
}
