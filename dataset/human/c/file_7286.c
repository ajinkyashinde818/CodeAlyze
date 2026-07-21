#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MOD (1000000007)

int n, L, x[6000], a[6000];
int dp[6000], s[6000];

int main() {
    scanf("%d%d", &n, &L);
    rep (i, n) scanf("%d", x+i);
    rep (i, n) scanf("%d", a+i);
    dp[L] = 1;
    for (int k = n-1; k >= 0; k--) {
        for (int i = L; i >= 0; i--) {
            s[i] = (s[i+1] + dp[i]) % MOD;
            if (a[k] == 0) {
                if (i == x[k]) dp[i] = s[i+1];
                else dp[i] = 0;
            }
            else {
                if (i >= x[k] && (i - x[k]) % a[k] == 0) dp[i] = s[i+1];
                else dp[i] = 0;
            }
        }
    }
    int ans = 0;
    rep (i, L) ans = (ans + dp[i]) % MOD;
    printf("%d\n", (int)ans);
    return 0;
}
