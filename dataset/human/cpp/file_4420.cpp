#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 200000;
int ai[N], bi[N], as[N], bs[N];
int vis[N], cc[N];
vector <int> bb[N];
int ans;
void dfs(int t)
{
    vis[t] = 1;
    for (int i = 0; i < bb[t].size(); ++ i)
        if (!vis[bb[t][i]]) dfs(bb[t][i]);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i)
    {
        scanf("%d", &ai[i]);
        ai[0] ^= ai[i];
    }
    for (int i = 1; i <= n; ++ i)
    {
        scanf("%d", &bi[i]);
        bi[0] ^= bi[i];
    }
    for (int i = 0; i <= n; ++ i)
        as[i] = ai[i], bs[i] = bi[i];
    sort(as, as + n + 1);
    sort(bs, bs + n + 1);
    for (int i = 0; i <= n; ++ i)
        if (as[i] != bs[i]) {puts("-1"); return 0;}
    for (int i = 0; i <= n; ++ i)
        ai[i] = lower_bound(as, as + n + 1, ai[i]) - as,
        bi[i] = lower_bound(bs, bs + n + 1, bi[i]) - bs;
    for (int i = 0; i <= n; ++ i)
        if (ai[i] != bi[i] || i == 0)
        {
            if (i) ans ++;
            cc[ai[i]] ++; cc[bi[i]] ++;
            bb[ai[i]].push_back(bi[i]);
            bb[bi[i]].push_back(ai[i]);
        }
    for (int i = 0; i <= n; ++ i)
        if (!vis[i] && cc[i])
            dfs(i), ans ++;
    ans --;
    ans = max(ans, 0);
    printf("%d\n", ans);
}
