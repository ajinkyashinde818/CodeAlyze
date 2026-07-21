#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MOD 1000000007
#define MAX 1000000

long long fac[MAX], finv[MAX], inv[MAX];

//http://drken1215.hatenablog.com/entry/2018/06/08/210000

void initComb() {
    fac[0] = 1; fac[1] = 1;
    finv[0] = 1;    finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}

long long int comb(int n, int k) {
    initComb();
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD;
}

int main(void) {
    int x, y;
    scanf("%d %d", &x, &y);
    int m, n;
    long long int ans;

    m = (2*y - x)/3;
    n = (2*x - y)/3;

    if ((x+y)%3 != 0) {
        ans = 0;
    } else if (m < 0 || n < 0) {
        ans = 0;
    } else {
        //ans = (m+n)C(m)
        ans = comb(m+n, m);
    }

    printf("%lld\n", ans);

    return 0;
}
