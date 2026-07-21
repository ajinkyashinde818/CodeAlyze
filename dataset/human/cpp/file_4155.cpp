#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <vector>
#include <complex>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <bitset>
#include <ctime>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cassert>
#include <cstddef>
#include <iomanip>
#include <numeric>
#include <tuple>
#include <sstream>
#include <fstream>
#include <chrono>
#include <random>

using namespace std;
#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define RREP(i, a) for(int (i) = (a) - 1; (i) >= 0; (i)--)
#define FORR(i, a, b) for(int (i) = (a) - 1; (i) >= (b); (i)--)
#define DEBUG(C) cerr << #C << " = " << C << endl;
using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<LL>;
using VVL = vector<VL>;
using VD = vector<double>;
using VVD = vector<VD>;
using PII = pair<int, int>;
using PDD = pair<double, double>;
using PLL = pair<LL, LL>;
using VPII = vector<PII>;
template<typename T> using VT = vector<T>;
#define ALL(a) begin((a)), end((a))
#define RALL(a) rbegin((a)), rend((a))
#define SORT(a) sort(ALL((a)))
#define RSORT(a) sort(RALL((a)))
#define REVERSE(a) reverse(ALL((a)))
#define MP make_pair
#define FORE(a, b) for (auto &&a : (b))
#define FIND(s, e) ((s).find(e) != (s).end())
#define EB emplace_back

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

using circle = pair<PII, double>;
int xs, ys, xg, yg;
int N;
VT<circle> xyr;

int main(void) {
    scanf("%d%d%d%d", &xs, &ys, &xg, &yg);
    scanf("%d", &N);
    xyr.resize(N + 2);
    xyr[0] = MP(MP(xs, ys), 0);
    xyr[N + 1] = MP(MP(xg, yg), 0);
    REP(i, N) {
        int x, y, r;
        scanf("%d%d%d", &x, &y, &r);
        xyr[i + 1] = MP(MP(x, y), r);
    }
    VD ans(N + 2, LLINF);
    VT<bool> vis(N + 2, false);
    ans[0] = 0;
    while (true) {
        double nowCost = LLINF;
        int nowId = -1;
         REP(i, N + 2) {
             if (!vis[i] && nowCost > ans[i]) {
                 nowCost = ans[i];
                 nowId = i;
             }
         }
         if (nowId == -1) break;
         vis[nowId] = true;
         int x1, y1, r1;
         x1 = xyr[nowId].first.first;
         y1 = xyr[nowId].first.second;
         r1 = xyr[nowId].second;
         REP(i, N + 2) {
             if (vis[i]) continue;
             int x2, y2, r2;
             x2 = xyr[i].first.first;
             y2 = xyr[i].first.second;
             r2 = xyr[i].second;
             double nextCost = nowCost + max(0.0, hypot(x1 - x2, y1 - y2) - r1 - r2);
             ans[i] = min(ans[i], nextCost);
         }
    }
    assert(count(ALL(vis), false) == 0);
    cout << fixed << setprecision(10) << ans[N + 1] << endl;
    return 0;
}
