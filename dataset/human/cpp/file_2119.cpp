#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set> 
#include <map>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstring>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); ++i)
#define FOR(i, a, b) for(int i=(a); i<(b); ++i)
typedef long long ll;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;

int main () {

    int n; cin >>n;
    vector<int> a(n); FOR (i, 0, n) cin >> a[i];
    vector<vector<ll> > d(n-1, vector<ll>(2,0));

    d[0][0] = a[0]+a[1];
    d[0][1] = -a[0]-a[1];
    for (int i = 1; i < n-1; i++) {
        d[i][0] = max(d[i-1][0] + a[i+1], d[i-1][1] + a[i+1]);
        d[i][1] = max(d[i-1][0] - 2*a[i] - a[i+1], d[i-1][1] + 2*a[i] - a[i+1]);
    }

    cout << max(d[n-2][0], d[n-2][1]) << endl;

    return 0;
}
