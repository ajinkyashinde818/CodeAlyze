#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
char S[200009];

int main() {
    long long ans = 1;
    int N; scanf("%d",&N);
    for(int i=1; i<=2*N; i++) scanf(" %c", &S[i]);
    int op = 0;
    for(int i=1; i<=2*N; i++) {
        if((S[i] == 'B') ^ (op & 1)) ++op;
        else {
            ans *= 1LL * op;
            ans %= MOD;
            --op;
        }
        if(op < 0) return !printf("0");
    }
    if(op != 0) return !printf("0");
    for(int i=1; i<=N; i++) ans *= 1LL * i, ans %= MOD;
    printf("%lld", ans);
    return 0;
}
