#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

typedef pair<double,int> PDI;

#define MP make_pair
#define PB push_back
#define FF first
#define SS second

#define FORN(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD(i, n) for (int i = (int)(n) - 1; i >= 0; i--)

#define DEBUG(X) { cout << #X << " = " << (X) << endl; }
#define PR0(A,n) { cout << #A << " = "; FORN(_,n) cout << A[_] << ' '; cout << endl; }

#define MOD 1000000007
#define INF 2000000000

int GLL(LL& x) {
    return scanf("%lld", &x);
}

int GI(int& x) {
    return scanf("%d", &x);
}

const int MAXN = 1005;

LL x[MAXN], y[MAXN], r[MAXN], visited[MAXN];

double d[MAXN];

int n;

priority_queue<PDI> dijk;

double c2c(int i, int j) {
    LL dx = x[i] - x[j];
    LL dy = y[i] - y[j];
    return sqrt(dx * dx + dy * dy);
}

LL xfin, yfin;

int main() {
    GLL(x[0]); GLL(y[0]);
    GLL(xfin); GLL(yfin);

    GI(n);

    r[0] = r[n+1] = 0;

    FOR1(i, n) {
        GLL(x[i]);
        GLL(y[i]);
        GLL(r[i]);
    }

    x[n+1] = xfin;
    y[n+1] = yfin;

    memset(visited, 0, sizeof visited);

    dijk.push(MP(0.0, 0));

    while (dijk.size() > 0) {
        PDI t = dijk.top(); dijk.pop();

        int u = t.SS; if (visited[u]) continue;

        d[u] = -t.FF;
        visited[u] = 1;

//        DEBUG(u);
//        DEBUG(d[u]);

        FOR1(v, n+1) {
            if (!visited[v]) {
                dijk.push(MP(t.FF - max(0.0, c2c(u, v) - r[u] - r[v]), v));
            }
        }
    }

    cout << setprecision(12) << d[n+1] << "\n";

    return 0;
}
