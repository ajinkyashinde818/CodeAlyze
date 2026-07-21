#include <bits/stdc++.h>
using namespace std;

using P = pair<int, int>;
using ll = long long;

struct edge {
    int from, to;
};

using edges = std::vector<edge>;
using graph = std::vector<edges>;

void add_edge(graph& g, int from, int to) {
    g[from].push_back((edge){from, to});
}


class lca {
public:
    lca(graph& g, int root)
        : V(g.size()),
          log_V(0),
          depth_(V, 0)
    {
        for(int v = V; v > 0; v /= 2) {
            ++log_V;
        }
        parent.assign(log_V, std::vector<int>(V, 0));
        dfs(g, root, -1, 0);
        for(int k=0; k+1 < log_V; ++k) {
            for(int v=0; v<V; ++v) {
                if(parent[k][v] < 0) {
                    parent[k+1][v] = -1;
                } else {
                    parent[k+1][v] = parent[k][parent[k][v]];
                }
            }
        }
    }

    void dfs(graph const& g, int v, int p, int d) {
        parent[0][v] = p;
        depth_[v] = d;
        for(int i=0; i<g[v].size(); ++i) {
            if(g[v][i].to != p) {
                dfs(g, g[v][i].to, v, d+1);
            }
        }
    }

    int depth(int v) const {
        return depth_[v];
    }

    int query(int u, int v) {
        if(depth_[u] > depth_[v]) {
            std::swap(u, v);
        }
        for(int k=0; k<log_V; ++k) {
            if((depth_[v] - depth_[u]) >> k & 1) {
                v = parent[k][v];
            }
        }
        if(u == v) {
            return u;
        }
        for(int k=log_V - 1; k>=0; --k) {
            if(parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }

private:
    int V, log_V;
    std::vector<vector<int>> parent;
    std::vector<int> depth_;
};

int main() {
    int n;
    cin >> n;
    graph g(n);
    for(int i=1; i<n; ++i) {
        int p;
        cin >> p;
        p--;
        add_edge(g, p, i);
    }
    for(int i=0; i<n; ++i) {
        sort(g[i].begin(), g[i].end(), [](auto const& e1, auto const& e2) {
            return e1.to < e2.to;
        });
    }
    vector<int> v(n);
    int id = 0;
    {
        queue<int> que;
        que.push(0);
        v[0] = 0;
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            for(auto& e : g[u]) {
                v[++id] = e.to;
                que.push(e.to);
            }
        }
    }
    lca l(g, 0);
    ll res = 0;
    for(int i=0; i<n-1; ++i) {
        int p = l.query(v[i], v[i+1]);
        res += l.depth(v[i]) + l.depth(v[i+1]) - 2*l.depth(p);
    }
    cout << res << endl;
}
