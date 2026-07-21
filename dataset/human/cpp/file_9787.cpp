#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9 + 7;
int cnt[33];

int main() {
    int N; scanf("%d",&N);
    while(N--) {
        char c; scanf(" %c",&c);
        ++cnt[c - 'a'];
    }
    long long ans = 1;
    for(int i=0; i<26; i++) ans *= (cnt[i] + 1), ans %= MOD;
    printf("%lld", (ans - 1 + MOD) % MOD);
    return 0;
}
