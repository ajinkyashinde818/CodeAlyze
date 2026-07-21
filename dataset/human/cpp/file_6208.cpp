#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <assert.h>
using namespace std;
 
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
typedef vector<double> VD;

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }

const ll INF = 1e18;

int main() {
    ll n, c;
    cin >> n >> c;
    VL x(n), v(n);
    REP(i,n){
        x[i] = lin();
        v[i] = lin();
    }

    VL pos(n);
    ll sum = 0;
    REP(i,n){
        sum += v[i];
        pos[i] = sum - x[i];
    }
    VL mal(n, -INF);
    mal[0] = pos[0];
    REP(i,n-1){
        mal[i+1] = max(mal[i], pos[i+1]);
    }

    VL neg(n);
    sum = 0;
    FORR(i,n-1,0){
        sum += v[i];
        neg[i] = sum - (c - x[i]);
    }
    VL mar(n, -INF);
    mar[n-1] = neg[n-1];
    FORR(i,n-1,1){
        mar[i-1] = max(mar[i], neg[i-1]);
    }

    ll ans = 0;
    REP(i,n){
        ans = max(ans, pos[i]);
        ans = max(ans, neg[i]);
    }

    sum = 0;
    FORR(i,n-1,1){
        sum += v[i];
        ans = max(ans, sum - 2 * (c - x[i]) + mal[i-1]);
    }

    sum = 0;
    REP(i,n-1){
        sum += v[i];
        ans = max(ans, sum - 2 * x[i] + mar[i+1]);
    }
    
    cout << ans << endl;

    return 0;
}
