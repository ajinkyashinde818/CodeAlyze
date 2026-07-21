#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dst, weight;
    Edge(int s, int d) : src(s), dst(d), weight(1) {}
    Edge(){}
};

using Edges = vector<Edge>;
using Graph = vector<Edges>;

struct HLDecomp {
    const Graph &g;
    int n;
    vector<vector<int>> chains;
    vector<int> parent, subtreeSize, depth, head, last, next, prev, chain, at;
    HLDecomp(const Graph &g_, int r = -1)
        : g(g_), n(g.size()), chains(0),
          parent(n, 0), subtreeSize(n, 0), depth(n, -1), head(n, 0),
          last(n, 0), next(n, -1), prev(n, -1), chain(n, -1), at(n, 0){
        if(r != -1) decompose(r);
    }
    int goUp(int v) const { return parent[head[v]]; }
    pair<int, int> getIndex(int v) const { return make_pair(chain[v], at[v]); }
    int size() const { return n; }
    void decompose(const int root){
        static int stk[600010], k = 0;
        stk[k++] = root; parent[root] = -1; depth[root] = 0;
        while(k){
            int v = stk[--k];
            if(v >= 0){
                stk[k++] = ~v;
                for(auto &e : g[v]){
                    int ch = e.dst;
                    if(depth[ch] == -1){
                        depth[ch] = depth[v] + 1;
                        parent[ch] = v;
                        stk[k++] = ch;
                    }
                }
            } else {
                int m = 0; v = ~v; subtreeSize[v] = 1;
                for(auto &e : g[v]){
                    int ch = e.dst;
                    if(parent[v] == ch) continue;
                    subtreeSize[v] += subtreeSize[ch];
                    if(m < subtreeSize[ch]){ m = subtreeSize[ch]; next[v] = ch; }
                }
            }
        }

        k = 0;
        stk[k++] = root;
        while(k){
            int h = stk[--k];
            for(auto &e : g[h]) if(parent[h] != e.dst) stk[k++] = e.dst;
            if(chain[h] != -1) continue;
            chains.push_back(vector<int>());
            vector<int> & path = chains.back();
            int cur = h;
            while(cur != -1){ path.push_back(cur); cur = next[cur]; }
            for(int i = 0; i < (int)path.size(); i++){
                int v = path[i];
                head[v] = path.front(); last[v] = path.back();
                next[v] = i+1 != (int)path.size() ? path[i+1] : -1;
                prev[v] = i != 0 ? path[i-1] : -1; chain[v] = chains.size() - 1; at[v] = i;
            }
        }
    }
    int lca(int u, int v){
        while(chain[u] != chain[v]){
            if(depth[head[u]] > depth[head[v]]) u = goUp(u);
            else v = goUp(v);
        }
        return depth[u] < depth[v] ? u : v;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while(cin >> n){
        Graph g(n);

        for(int i = 1; i < n; ++i){
            int p;
            cin >> p;
            --p;
            g[i].emplace_back(i,p);
            g[p].emplace_back(p,i);
        }

        for(int i = 0; i < n; ++i){
            sort(begin(g[i]), end(g[i]), [](Edge a, Edge b){
                    return a.dst < b.dst;
                });
        }

        auto hld = HLDecomp(g,0);

        long long ans = 0;
        int prev = -1;
        queue<int> q;
        vector<int> vis(n);
        q.emplace(0);
        while(q.size()){
            int v = q.front();
            q.pop();
            vis[v] = true;

            if(prev != -1){
                int p = hld.lca(v,prev);
                ans += hld.depth[v] + hld.depth[prev] - 2*hld.depth[p];
            }

            prev = v;
            for(auto &e : g[v]){
                if(!vis[e.dst]){
                    q.emplace(e.dst);
                }
            }
        }

        cout << ans << endl;
    }
}
