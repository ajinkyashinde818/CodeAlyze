#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<utility>
#include<cmath>
#include<assert.h>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>

#define int long long
using namespace std;
#define rep(i, n) for(int i=0;i<(n);++i)
typedef pair<int, int> pii;
const int INF = 1l << 60;
#define u_b upper_bound
#define l_b lower_bound

int N;
int X[1010], Y[1010], R[1010];
double d[1010][1010];
double dd[1010];

void dijkstra() {
    rep(i, 1010)dd[i] = INF;
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> que;
    dd[0] = 0;
    que.push(make_pair(0, 0));
    while (!que.empty()) {
        pair<double, int> p = que.top();
        que.pop();
        int v = p.second;
        if (dd[v] < p.first)continue;
        rep(j, N + 2) {
            if (dd[j] > dd[v] + d[v][j]) {
                dd[j] = dd[v] + d[v][j];
                que.push(make_pair(dd[j], j));
            }
        }
    }
}

signed main() {
    int xt, yt;
    cin >> X[0] >> Y[0] >> xt >> yt;
    cin >> N;
    X[N + 1] = xt;
    Y[N + 1] = yt;
    rep(i, N) {
        cin >> X[i + 1] >> Y[i + 1] >> R[i + 1];
    }
    rep(i, N + 2) {
        for (int j = i + 1; j < N + 2; ++j) {
            d[i][j] = (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]);
            d[i][j] = sqrt(d[i][j]) - R[i] - R[j];
            if (d[i][j] < 0)d[i][j] = 0;
            d[j][i] = d[i][j];
        }
    }
    dijkstra();
    printf("%.20lf", dd[N + 1]);
    return 0;
}
