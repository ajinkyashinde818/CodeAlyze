#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <string>
#include <vector>

using LL = long long;
const int kN = 200000 + 5;
int n;
LL L;
int go[kN][2];
int root = 1, tot = 2;
int sg[kN];
int depth[kN];

std::string show(int d)
{
    std::string ret;
    while (d) {
        ret.push_back(d % 2 + '0');
        d /= 2;
    }
    std::reverse(ret.begin(), ret.end());
    return ret;
}

LL entire_sg(LL d)
{
    if (d < 0) return 0;
    if (d == 0) return 1;
    // return sg[d];
    d += 1;
    int c = 0;
    while (~d & 1) ++ c, d >>= 1;
    return 1LL << c;
}

int main()
{
    sg[0] = 1;
    for (int i = 1; i <= 1000; ++ i) {
        std::set<int> set;
        for (int j = 0; j < i; ++ j) {
            int val = 0;
            for (int k = j; k < i; ++ k)
                val ^= sg[k];
            set.emplace(val);
        }
        int x = 1;
        while (set.count(x)) ++ x;
        sg[i] = x;
        // printf("sg[%d] = %d, %s\n", i, x, show(i + 1).c_str());
    }
    // return 0;

    scanf("%d%lld", &n, &L);
    for (int i = 0; i < n; ++ i) {
        static char s[kN];
        scanf("%s", s);
        int u = root;
        for (int j = 0; s[j]; ++ j) {
            int c = s[j] - '0';
            if (go[u][c] == 0) {
                go[u][c] = tot ++;
                depth[go[u][c]] = depth[u] + 1;
            }
            u = go[u][c];
        }
    }

    LL val = 0;
    for (int u = tot - 1; u > 0; -- u) {
        if (go[u][0] + go[u][1] == 0) continue;
        for (int c = 0; c < 2; ++ c) {
            if (go[u][c] == 0) {
                // printf("u = %d, c = %d, depth[u] = %d\n", u, c, depth[u]);
                val ^= entire_sg(L - depth[u] - 1);
                // printf("got %lld, %lld\n", L - depth[u] - 1, entire_sg(L - depth[u] - 1));
            }
        }
    }
    puts(val ? "Alice" : "Bob");
}
