#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, a[N], b[N], ans;
map<int, int> rd, fa;
inline int Ask(int x) {
    return fa.count(x) ? fa[x] = Ask(fa[x]) : x;
}
inline void Merge(int x, int y) {
    x = Ask(x); y = Ask(y);
    if (x == y) return;
    fa[x] = y;
}
int main() {
    scanf("%d", &n);
    int a_xor = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        a_xor ^= a[i];
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", b + i);
        if (a[i] != b[i]) {
            ++rd[a[i]];
            --rd[b[i]];
            Merge(a[i], b[i]);
            ++ans;
        }
    }
    if (!ans) return puts("0"), 0;
    int non_zero_cnt = 0, rt = Ask(a_xor), con_num = 0;
    for (map<int, int>::iterator it = rd.begin(); it != rd.end(); ++it) {
        if (Ask(it->first) == rt) non_zero_cnt += bool(it->second);
        else if (it->second) return puts("-1"), 0;
        con_num += !fa.count(it->first);
    }
    if (!rd.count(a_xor)) {
        printf("%d\n", ans + con_num);
    } else {
        if ((rd[a_xor] == 0 && non_zero_cnt == 0) || (rd[a_xor] == -1 && non_zero_cnt == 2)) {
            printf("%d\n", ans + con_num - 1);
        } else {
            puts("-1");
        }
    }
    return 0;
}
