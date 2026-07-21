#include <stdio.h>

int MOD = 1000000007;
long long fact[1000005], finv[1000005], inv[1000005];

void f1(void) {
    fact[0] = fact[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < 1000005; i++){
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long f2(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fact[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(void) {
    f1();
    int X, Y, N;
    scanf("%d%d", &X, &Y);
    if ((X+Y)%3!=0 || X>2*Y || Y>2*X) {
        printf("%d", 0);
        return 0;
    }
    else N=(X+Y)/3;
    X=X-N; Y=Y-N;
    printf("%lld", f2(X+Y, X));
    return 0;
}
