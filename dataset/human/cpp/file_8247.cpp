// #define _GLIBCXX_DEBUG // for STL debug (optional)
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
using namespace std;
using ll = long long int;
using int64 = long long int;
 
template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int INF = 1LL << 29;
const ll LONGINF = 1LL << 60;
const ll MOD = 1000000007LL;

// HL 分解 (Heavy-Light Decomposition)
// 頂点 v を根とする部分木: [ in[v], out[v] )
// 頂点 v から見た heavy edge chain の頭: head[v]
struct HLD {
    vector< vector<int> > G;
    vector<int> sub, par, depth, in, out, rev, head;
    
    void dfs_sub(int cur) {
        for(auto& to : G[cur]) {
            if(par[cur] == to) continue;
            par[to] = cur;
            depth[to] = depth[cur] + 1;
            dfs_sub(to);
            sub[cur] += sub[to];
            if(sub[to] > sub[ G[cur][0] ]) swap(to, G[cur][0]);
        }
    }
    void dfs_hld(int cur, int& ptr) {
        in[cur] = ptr; rev[ptr++] = cur;
        for(auto to : G[cur]) {
            if(par[cur] == to) continue;
            head[to] = (to == G[cur][0] ? head[cur] : to);
            dfs_hld(to, ptr);
        }
        out[cur] = ptr;
    }

    HLD(int N) : G(N), sub(N, 1), par(N, -1), depth(N),
                 in(N), out(N), rev(N), head(N) {}
    void add_edge(int u, int v) {
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    void build(int root=0) {
        int ptr = 0; dfs_sub(root); dfs_hld(root, ptr);
    }
    int lca(int u, int v) {
        while(1) {
            if(in[u] > in[v]) swap(u, v);
            if(head[u] == head[v]) return u;
            v = par[ head[v] ];
        }
    }
    int distance(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }

    template <typename F>
    void proceed(int u, int v, const F& f, bool b) {
        for(; head[u] != head[v]; v = par[ head[v] ]) {
            if(in[u] > in[v]) swap(u, v);
            f(in[ head[v] ], in[v] + 1);
        }
        if(in[u] > in[v]) swap(u, v);
        f(in[u] + b, in[v] + 1);
    }

    // u - v パス上に存在する「頂点」or「辺」全体に f(l, r) を作用
    // l, r は SegmentTree とかのデータ構造上のインデックス
    template <typename F>
    void query_vertices(int u, int v, const F& f) {
        proceed(u, v, f, false);
    }

    template <typename F>
    void query_edges(int u, int v, const F& f) {
        proceed(u, v, f, true);
    }

    template <typename T, typename F, typename M>
    T proceed(int u, int v, T E, const F& f, const M& m, bool b) {
        T vl(E), vr(E);
        for(; head[u] != head[v]; v = par[ head[v] ]) {
            if(in[u] > in[v]) swap(u, v), swap(vl, vr);
            vr = m(f(in[ head[v] ], in[v] + 1), vr);
        }
        if(in[u] > in[v]) swap(u, v), swap(vl, vr);
        vr = m(f(in[u] + b, in[v] + 1), vr);
        return m(vl, vr);
    }

    // u - v パス上に存在する「頂点」or「辺」全体に割り当てられた値を
    // 各 chunk に対して f(l, r) で得て、それらを m(vl, vr) で merge したものを得る
    // 単位元 E も渡そう
    template <typename T, typename F, typename M>
    T query_vertices(int u, int v, T E, const F& f, const M& m) {
        return proceed(u, v, E, f, m, false);
    }

    template <typename T, typename F, typename M>
    T query_edges(int u, int v, T E, const F& f, const M& m) {
        return proceed(u, v, E, f, m, true);
    }
};

// @category セグメント木 (Segment Tree)
// @title 双対セグメント木 (Dual Segment Tree)
// 双対セグメント木 (Dual Segment Tree)
// ref: https://kimiyuki.net/blog/2019/02/22/dual-segment-tree/
template <typename MonoidType, typename OperatorType>
struct DualSegmentTree {
    using MOtoM = function< MonoidType(MonoidType, OperatorType) >;
    using OOtoO = function< OperatorType(OperatorType, OperatorType) >;

    int n;
    vector<MonoidType> bottom;
    vector<OperatorType> lazy;
    OperatorType E;

    // update / lazy function
    MOtoM upd_f;
    OOtoO lzy_f;

    inline void build(const vector<MonoidType> &v) {
        int m = v.size();
        n = 1; while(n < m) n *= 2;
        bottom = v; bottom.resize(n);
        lazy.resize(n - 1, E);
    }

    DualSegmentTree() {}
    DualSegmentTree(OperatorType E_,
                    MOtoM upd_f_, OOtoO lzy_f_,
                    vector<MonoidType> v = vector<MonoidType>()) :
        E(E_), upd_f(upd_f_), lzy_f(lzy_f_) {
        build(v);
    }

    void update(int a, int b, OperatorType x, int l, int r, size_t k) {
        if(b <= l or r <= a) return;
        if(a <= l and r <= b) {
            if(k < lazy.size())
                lazy[k] = lzy_f(lazy[k], x);
            else
                bottom[k-n+1] = upd_f(bottom[k-n+1], x);
        }
        else {
            int mid = (l + r) >> 1;
            update(0, n, lazy[k], l, mid, 2*k+1);
            update(0, n, lazy[k], mid, r, 2*k+2);
            lazy[k] = E;
            update(a, b, x, l, mid, 2*k+1);
            update(a, b, x, mid, r, 2*k+2);
        }
    }

    void update(int a, int b, OperatorType x) {
        update(a, b, x, 0, n, 0);
    }

    MonoidType query(int k) {
        MonoidType res = bottom[k];
        for(k = (k+n)>>1; k>0; k>>=1) { // 1-indexed
            res = upd_f(res, lazy[k-1]);
        }
        return res;
    }
};


// @category セグメント木 (Segment Tree)
// @title セグメント木 (Segment Tree)
// 抽象 SegmentTree (0-indexed・一点更新・区間取得)
template <typename MonoidType>
struct SegmentTree {
    using Function = function< MonoidType(MonoidType, MonoidType) >;

    // node, identity element
    int n;
    vector<MonoidType> node;
    MonoidType E0;

    // update / combine function
    Function upd_f, cmb_f;

    void build(int m, vector<MonoidType> v = vector<MonoidType>()) {
        if(v != vector<MonoidType>()) m = v.size();
        n = 1; while(n < m) n *= 2;

        node = vector<MonoidType>(2*n-1, E0);
        if(v != vector<MonoidType>()) {
            for(int i=0; i<m; i++) {
                node[n-1+i] = v[i];
            }
            for(int i=n-2; i>=0; i--) {
                node[i] = cmb_f(node[2*i+1], node[2*i+2]);
            }
        }
    }

    // initialize
    SegmentTree() {}
    SegmentTree(int n_, MonoidType E0_,
                Function upd_f_, Function cmb_f_,
                vector<MonoidType> v = vector<MonoidType>()) :
        E0(E0_), upd_f(upd_f_), cmb_f(cmb_f_) {
        build(n_, v);
    }

    // update k-th element (applied value: x)
    void update(int k, MonoidType x) {
        k += n - 1;
        node[k] = upd_f(node[k], x);
        while(k > 0) {
            k = (k - 1) / 2;
            node[k] = cmb_f(node[2*k+1], node[2*k+2]);
        }
    }

    // range query for [a, b)
    // 非再帰のアイデア: http://d.hatena.ne.jp/komiyam/20131202/1385992406
    MonoidType query(int a, int b) {
        MonoidType vl = E0, vr = E0;
        for(int l=a+n, r=b+n; l<r; l>>=1, r>>=1) {
            if(l & 1) vl = cmb_f(vl, node[(l++)-1]);
            if(r & 1) vr = cmb_f(node[(--r)-1], vr);
        }
        return cmb_f(vl, vr);
    }
};


int main() {
    int N, Q; cin >> N >> Q;
    HLD hl(N);
    for(int i=0; i<N-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        hl.add_edge(u, v);
    }
    hl.build();

    vector<int> sub(N);
    for(int i=0; i<N; i++) {
        sub[i] = hl.sub[ hl.rev[i] ];
    }

    DualSegmentTree<int, int> seg(0,
                                  [](int a, int b) { return a + b; },
                                  [](int a, int b) { return a + b; },
                                  sub);

    SegmentTree<int> sum(N, 0,
                         [](int a, int b) { return a + b; },
                         [](int a, int b) { return a + b; });

    const int B = 20;
    vector< vector<int> > par(N, vector<int>(B));
    for(int i=0; i<N; i++) par[i][0] = hl.par[i];
    for(int d=1; d<B; d++) {
        for(int i=0; i<N; i++) {
            if(par[i][d-1] < 0) par[i][d] = -1;
            else par[i][d] = par[ par[i][d-1] ][d-1];
        }
    }

    vector<int> is_white(N, 1);
    for(int i=0; i<Q; i++) {
        int t, v; cin >> t >> v; v--;

        // mark されていないところまで登る
        int cur = v;
        for(int d=B-1; d>=0; d--) {
            if(par[cur][d] < 0) continue;
            int p = par[cur][d];
            
            auto acc = [&](int l, int r) {
                return sum.query(l, r);
            };
            auto merge = [&](int a, int b) {
                return a + b;
            };

            // mark されている数 (黒の数) を数える
            if(hl.query_vertices(cur, p, 0, acc, merge) - !is_white[cur]) continue;
            cur = p;
        }

        if(t == 1) {
            // 最初に mark されたところ (存在しなければ移動しない)
            if(par[cur][0] >= 0) cur = par[cur][0];
            int root = cur;
            // fprintf(stderr, "root = %d\n", root);
            
            int add = seg.query(hl.in[v]);
            if(is_white[v]) add *= -1;
            auto upd1 = [&](int l, int r) {
                seg.update(l, r, add);
            };
            auto upd2 = [&](int l, int r) {
                seg.update(l, r, -add);
            };
            hl.query_vertices(root, v, upd1);
            hl.query_vertices(v, v, upd2);

            int pls = (is_white[v] ? +1 : -1);
            auto upd3 = [&](int l, int r) {
                sum.update(l, pls);
            };
            hl.query_vertices(v, v, upd3);

            is_white[v] = 1 - is_white[v];
        }
        if(t == 2) {
            // mark されてないところの seg の値
            // fprintf(stderr, "cur = %d\n", cur);
            int res = seg.query(hl.in[cur]);
            cout << res << endl;
        }
    }
    return 0;
}
