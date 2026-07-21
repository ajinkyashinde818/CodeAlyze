// Written By NewbieChd
#include <cstdio>
using namespace std;

const int maxN = 2000003, mod = 1e9 + 7;
char s[maxN];

int main() {
    int n, i, ans = 1, tmp = 1;
    bool dir = 1;
    scanf("%d%s", &n, s + 1);
    if (s[1] != 'B') {
        printf("0\n");
        return 0;
    }
    for (i = 1; i <= n; ++i)
        ans = 1ll * ans * i % mod;
    n <<= 1;
    for (i = 2; i <= n; ++i) {
        if (s[i] == s[i - 1])
            dir ^= 1;
        if (dir)
            ++tmp;
        else
            ans = 1ll * ans * tmp % mod, --tmp;
    }
    printf("%d\n", tmp ? 0 : ans);
    return 0;
}
