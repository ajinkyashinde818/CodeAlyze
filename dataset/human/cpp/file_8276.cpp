#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;
using P = pair<int, int>;
constexpr ld EPS = 1e-12;
constexpr int INF = numeric_limits<int>::max() / 2;
constexpr int MOD = 1e9 + 7;

int n;

class LCA
{
    int n, log_n;
    vector<vector<int>> parent;
    vector<int> depth;
    void dfs(const vector<vector<int>> &g, int v, int p, int d)
    {
        parent[0][v] = p;
        depth[v] = d;
        for (int i = 0; i < (int)g[v].size(); i++)
        {
            if (g[v][i] != p)
                dfs(g, g[v][i], v, d + 1);
        }
    }

  public:
    LCA(const vector<vector<int>> &g, int root) : n(g.size()), log_n(0), depth(n, 0)
    {
        for (int v = n; v > 0; v /= 2)
            log_n++;
        parent.assign(log_n, vector<int>(n, 0));
        dfs(g, root, -1, 0);
        for (int k = 0; k < log_n - 1; k++)
        {
            for (int v = 0; v < n; v++)
            {
                if (parent[k][v] < 0)
                    parent[k + 1][v] = -1;
                else
                    parent[k + 1][v] = parent[k][parent[k][v]];
            }
        }
    }
    int query(int u, int v)
    {
        if (depth[u] > depth[v])
            swap(u, v);
        for (int k = 0; k < log_n; k++)
        {
            if (((depth[v] - depth[u]) >> k) & 1)
            {
                v = parent[k][v];
            }
        }
        if (u == v)
            return u;
        for (int k = log_n - 1; k >= 0; k--)
        {
            if (parent[k][u] != parent[k][v])
            {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++)
    {
        int p;
        cin >> p;
        p--;
        g[p].push_back(i);
    }
    vector<int> visit;
    vector<int> dist(n, INF);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        visit.push_back(v);
        for (auto next : g[v])
        {
            dist[next] = dist[v] + 1;
            q.push(next);
        }
    }
    LCA lca(g, 0);
    ll res = 0;
    for(int i=1;i<n;i++){
        int cur=visit[i],pre=visit[i-1];
        int p=lca.query(cur,pre);
        res += (dist[cur]-dist[p]) + (dist[pre]-dist[p]);
    }
    cout<<res<<endl;
}
