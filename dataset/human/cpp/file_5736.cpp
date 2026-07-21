#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
const LL N = 1000000+10;
LL ch[N][2], tot;
LL n, L;
char s[N];
void insert(LL len, char * s) {
    LL now = 0; 
    for (LL i = 1; i <= len; i ++) {
        LL f = (s[i] == '1') ? 1 : 0;
        if (!ch[now][f]) {
            ch[now][f] = ++ tot;
        }
        now = ch[now][f];
    }
}
LL dfs(LL x, LL dep) {
    if (dep > L) return 0;
    if (x == 0 && dep != 0) {
        return (L-dep+1)&(-L+dep-1);
    }
    return dfs(ch[x][0], dep + 1) ^ dfs(ch[x][1], dep + 1);
}
int main() {
    scanf("%lld %lld", &n, &L);
    for (LL i = 1; i <= n; i ++) {
        scanf("%s", s+1);
        LL len = strlen(s+1);
        insert(len, s);
    }
    printf("%s\n", dfs(0, 0) ? "Alice" : "Bob");
}
