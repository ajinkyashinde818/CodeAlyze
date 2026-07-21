#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int nax = 4e5 + 10;
namespace atcoder {
// Reference:
// B. Aspvall, M. Plass, and R. Tarjan,
// A Linear-Time Algorithm for Testing the Truth of Certain Quantified Boolean
// Formulas
namespace internal {
template <class E> struct csr {
    std::vector<int> start;
    std::vector<E> elist;
    csr(int n, const std::vector<std::pair<int, E>>& edges)
        : start(n + 1), elist(edges.size()) {
        for (auto e : edges) {
            start[e.first + 1]++;
        }
        for (int i = 1; i <= n; i++) {
            start[i] += start[i - 1];
        }
        auto counter = start;
        for (auto e : edges) {
            elist[counter[e.first]++] = e.second;
        }
    }
};

// Reference:
// R. Tarjan,
// Depth-First Search and Linear Graph Algorithms
struct scc_graph {
  public:
    scc_graph(int n) : _n(n) {}

    int num_vertices() { return _n; }

    void add_edge(int from, int to) { edges.push_back({from, {to}}); }

    // @return pair of (# of scc, scc id)
    std::pair<int, std::vector<int>> scc_ids() {
        auto g = csr<edge>(_n, edges);
        int now_ord = 0, group_num = 0;
        std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);
        visited.reserve(_n);
        auto dfs = [&](auto self, int v) -> void {
            low[v] = ord[v] = now_ord++;
            visited.push_back(v);
            for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                auto to = g.elist[i].to;
                if (ord[to] == -1) {
                    self(self, to);
                    low[v] = std::min(low[v], low[to]);
                } else {
                    low[v] = std::min(low[v], ord[to]);
                }
            }
            if (low[v] == ord[v]) {
                while (true) {
                    int u = visited.back();
                    visited.pop_back();
                    ord[u] = _n;
                    ids[u] = group_num;
                    if (u == v) break;
                }
                group_num++;
            }
        };
        for (int i = 0; i < _n; i++) {
            if (ord[i] == -1) dfs(dfs, i);
        }
        for (auto& x : ids) {
            x = group_num - 1 - x;
        }
        return {group_num, ids};
    }

    std::vector<std::vector<int>> scc() {
        auto ids = scc_ids();
        int group_num = ids.first;
        std::vector<int> counts(group_num);
        for (auto x : ids.second) counts[x]++;
        std::vector<std::vector<int>> groups(ids.first);
        for (int i = 0; i < group_num; i++) {
            groups[i].reserve(counts[i]);
        }
        for (int i = 0; i < _n; i++) {
            groups[ids.second[i]].push_back(i);
        }
        return groups;
    }

  private:
    int _n;
    struct edge {
        int to;
    };
    std::vector<std::pair<int, edge>> edges;
};
}


struct two_sat {
  public:
    two_sat() : _n(0), scc(0) {}
    two_sat(int n) : _n(n), _answer(n), scc(2 * n) {}

    void add_clause(int i, bool f, int j, bool g) {
        assert(0 <= i && i < _n);
        assert(0 <= j && j < _n);
        scc.add_edge(2 * i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));
        scc.add_edge(2 * j + (g ? 0 : 1), 2 * i + (f ? 1 : 0));
    }
    bool satisfiable() {
        auto id = scc.scc_ids().second;
        for (int i = 0; i < _n; i++) {
            if (id[2 * i] == id[2 * i + 1]) return false;
            _answer[i] = id[2 * i] < id[2 * i + 1];
        }
        return true;
    }
    std::vector<bool> answer() { return _answer; }

  private:
    int _n;
    std::vector<bool> _answer;
    internal::scc_graph scc;
};
}
using two_sat = atcoder::two_sat;


using two_sat = atcoder::two_sat;
int a[nax];
int b[nax];
int first[nax];
int last[nax];

pair <int, int> ban[nax];
int top_ban = 0;
int n;

int main() {
    scanf("%d", &n);

    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d", a + i);
        if (!first[a[i]]) first[a[i]] = i;
        last[a[i]] = i;
    }

    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d", b + i);
    }


    for (int i = 1 ; i <= n ; ++ i) {
        int x = first[b[i]], y = last[b[i]];
        if (x == 0) continue;
        int ban_l, ban_r;
        if (i <= x) {
            ban_l = x - i;
            ban_r = ban_l + y - x;
        } else {
            x += n; y += n;
            ban_l = x - i;
            ban_r = ban_l + y - x;
        }

        if (ban_r >= n) {
            ban[++ top_ban] = make_pair(0, ban_r - n);
            ban[++ top_ban] = make_pair(ban_l, n - 1);
        } else ban[++ top_ban] = make_pair(ban_l, ban_r);
    }

    /**
        if matching exist, it's one of cyclic shift
        not we can express it as some boolean clause?
        ban range has logical expression as
        not(x >= a && x <= b)
        = not(x >= a) || (x >= b - 1)
        not just and all of these clause
        and add some additional clause
        if (x >= a)-> (x >= a - 1)
        equivalent to not(x >= a) or x >= a - 1;
    */

    two_sat sat(n);
    for (int i = 1 ; i < n ; ++ i) {
        sat.add_clause(i, false, i - 1, true);
    }

    for (int i = 1 ; i <= top_ban ; ++ i) {
        auto [l, r] = ban[i];
   //     cout << l << ' ' << r << '\n';
        if (r == n - 1)
        sat.add_clause(l, false, l, false);
        else sat.add_clause(l, false, r + 1, true);
    }
    sat.add_clause(0, true, 0, true);

    if (!sat.satisfiable()) return !printf("No");

    vector <bool> answer = sat.answer();

    int last_true = 0;

    for (const auto &it : answer) {
  //      cout << it << ' ';
    }
  //  cout << '\n';

    for (int i = 0 ; i < n ; ++ i) {
        if (answer[i]) {
            last_true = i;
        } else break;
    }

    //cerr << "LAST TRUE " << last_true << '\n';
    printf("Yes\n");

    for (int i = 1 ; i <= n ; ++ i) {
        int pos = i - last_true;
        if (pos <= 0) pos += n;
        printf("%d ", b[pos]);
    }
}
