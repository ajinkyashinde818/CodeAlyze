#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <functional>

using namespace std;
using lint = long long;

const int INF = 1 << 30;

struct SegmentTree {
    int N;
    vector<int> data;

    SegmentTree(int N) : N(N), data(N * 2, INF) {}

    int query(int l, int r) {
        l += N, r += N;
        int ret = INF;
        while (l < r) {
            if (l & 1) {
                ret = min(ret, data[l]);
                ++l;
            }
            if (r & 1) {
                ret = min(ret, data[r - 1]);
                --r;
            }
            l >>= 1;
            r >>= 1;
        }
        return ret;
    }

    void update(int i, int v) {
        i += N;
        data[i] = v;
        i >>= 1;
        while (i > 0) {
            data[i] = min(data[i * 2], data[i * 2 + 1]);
            i >>= 1;
        }
    }
};

int main() {
    int N;
    cin >> N;

    vector<vector<int>> ch(N);
    for (int v = 1; v < N; ++v) {
        int p;
        cin >> p;
        ch[--p].push_back(v);
    }

    vector<int> depth(N), tour;
    function<void(int, int)> dfs = [&](int v, int d) {
        depth[v] = d;
        tour.push_back(v);
        for (int sv : ch[v]) {
            dfs(sv, d + 1);
            tour.push_back(v);
        }
    };
    dfs(0, 0);

    int M = tour.size();

    vector<int> first(N, -1);
    for (int i = 0; i < tour.size(); ++i) {
        if (first[tour[i]] < 0) {
            first[tour[i]] = i;
        }
    }

    SegmentTree seg(M);
    for (int i = 0; i < tour.size(); ++i) {
        seg.update(i, depth[tour[i]]);
    }

    int prev = -1;
    queue<int> que;
    que.push(0);

    lint ans = 0;
    while (!que.empty()) {
        int v = que.front();
        que.pop();

        if (prev >= 0) {
            int l = min(first[prev], first[v]);
            int r = max(first[prev], first[v]);

            ans += depth[prev] + depth[v] -
                   seg.query(l, r + 1) * 2;
        }
        prev = v;
        for (auto sv : ch[v]) que.push(sv);
    }

    cout << ans << endl;
    return 0;
}
