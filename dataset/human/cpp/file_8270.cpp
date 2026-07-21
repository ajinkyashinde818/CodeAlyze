#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

// 移動元と行先と辺のコストを記録する構造体
template <typename T>
struct Edge {
    int from, to;
    T cost;
    Edge(int s, T d) : to(s), cost(d) {}
    Edge(int f, int s, T d) : from(f), to(s), cost(d) {}

    bool operator<(const Edge &e) const {
        return to < e.to;
    }
};

template <typename T>
using Graph = vector< vector< Edge<T> > >;

// 最小共通先祖 (Lowest Common Ancestor, LCA) を求める
// Verified: AOJ GRL_5_C (Lowest Common Ancestor)

template <typename T>
struct TreeLCA {
public:
    int const MAX_LOG_V;
    vector< vector< Edge<T> > > G;
    int root, vn;
    vector< vector<int> > parent;
    vector<int> depth;

    // constructor (Graph, root)
    TreeLCA(vector< vector< Edge<T> > > &_G, int _r) : 
        MAX_LOG_V(35), G(_G), root(_r), vn(G.size()), 
        parent(MAX_LOG_V, vector<int>(vn, 0)), depth(vn, -1)
        { depth[root] = 0; init(vn); }

    void dfs(int v, int p, int d) {
        parent[0][v] = p;
        depth[v] = d;
        for(int i=0; i<G[v].size(); i++) {
            if(depth[ G[v][i].to ] >= 0) continue;
            if(G[v][i].to != p) dfs(G[v][i].to, v, d+1);
        }
    }

    void init(int V) {
        dfs(root, -1, 0);
        for(int k=0; k+1 < MAX_LOG_V; k++) {
            for(int v=0; v < V; v++) {
                if(parent[k][v] < 0) parent[k+1][v] = -1;
                else parent[k+1][v] = parent[k][parent[k][v]];
            }
        }
    }

    // u と v の最小共通祖先
    int lca(int u, int v) {
        if(depth[u] > depth[v]) swap(u, v);
        for(int k=0; k < MAX_LOG_V; k++) {
            if((depth[v] - depth[u]) >> k & 1) {
                v = parent[k][v];
            }
        }
        if(u == v) return u;
        for(int k=MAX_LOG_V - 1; k>=0; k--) {
            if(parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }

    // u と v のパスの長さ (LCA を使って計算)
    int dist(int u, int v) {
        int anc = lca(u, v);
        return depth[u] + depth[v] - 2 * depth[anc];
    }
};

int main() {
    int N; scanf("%d", &N);
    Graph<int> G(N);
    for(int i=1; i<N; i++) {
        int par; scanf("%d", &par); par--;
        G[par].push_back(Edge<int>(i, 1));
    }
    for(int i=0; i<N; i++) {
        sort(G[i].begin(), G[i].end());
    }

    int root = 0, u = 0;
    long long int ans = 0;
    TreeLCA<int> lca(G, root);
    vector< Edge<int> > children = G[root];
    int max_depth = *max_element(lca.depth.begin(), lca.depth.end());
    for(int t=0; t<max_depth; t++) {
        vector< Edge<int> > nxt_children;
        for(auto e : children) {
            int v = e.to;
            // printf("dist (%d and %d): %d\n", u+1, v+1, lca.dist(u, v));
            ans += (long long int)lca.dist(u, v);
            u = e.to;
            for(auto x : G[v]) {
                nxt_children.push_back(x);
            }
        }
        swap(nxt_children, children);
    }
    printf("%lld\n", ans);
    return 0;
}
