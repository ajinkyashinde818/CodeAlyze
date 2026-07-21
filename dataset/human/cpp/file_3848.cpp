#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>

#define int long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define PB push_back
#define MP make_pair
#define FST first
#define SND second
#define SZ(a) (signed)((a).size())
#define EACH(i, c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define EXIST(s, e) ((s).find(e) != (s).end())
#define SORT(c) sort((c).begin(), (c).end())

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;

const int MOD = 1000000007;

#define dump(x) cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")"  << " " << __FILE__ << endl;

signed main(void) {
    ios::sync_with_stdio(false);
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(10);
    cin.tie(0);

    int xs, ys, xt, yt, n;
    cin >> xs >> ys >> xt >> yt >> n;
    VI x(n), y(n), r(n);
    REP(i, n) {
        cin >> x[i] >> y[i] >> r[i];
    }


    vector<vector<double>> edge(n + 2, vector<double>(n + 2, 0));
    REP(i, n) {
        FOR(j, i + 1, n) {
            double l = max(sqrt(pow((double) x[i] - x[j], 2) + pow((double) y[i] - y[j], 2)) - r[i] - r[j], 0.0);
            edge[i][j] = l;
            edge[j][i] = l;
        }
    }

    REP(i, n) {
        double l = max(sqrt(pow((double) x[i] - xs, 2) + pow((double) y[i] - ys, 2)) - r[i], 0.0);
        edge[i][n] = l;
        edge[n][i] = l;
    }

    REP(i, n) {
        double l = max(sqrt(pow((double) x[i] - xt, 2) + pow((double) y[i] - yt, 2)) - r[i], 0.0);
        edge[i][n+1] = l;
        edge[n+1][i] = l;
    }

    double l = max(sqrt(pow((double) xs - xt, 2) + pow((double) ys - yt, 2)), 0.0);
    edge[n][n+1] = l;
    edge[n+1][n] = l;

    priority_queue<pair<double,int>> pq;
    vector<bool> vb(n+2,false);
    vector<double>  ans(n+2,-0.0);
    pq.push(MP(0,n));

    while (!pq.empty()){
        pair<double,int> t = pq.top();
        pq.pop();
        if(vb[t.SND]){ continue; }
        vb[t.SND] = true;
        ans[t.SND] = -t.FST;
        REP(i,n+2){
            if(vb[i]){ continue; }
            else{
                pq.push(MP(t.FST-edge[t.SND][i],i));
            }
        }
    }

    cout << abs(ans[n+1])  << endl;

    return 0;
}
