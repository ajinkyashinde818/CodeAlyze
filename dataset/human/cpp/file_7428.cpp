#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set> 
#include <map>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iomanip>
#define REP(i,n) for(int i=0; i<(n); ++i)
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const ll INFLL = 1001001001001001001;  // > 10^18
const int MOD = (int)1e9 + 7;
const ll MODLL = (ll)1e9 + 7;
const double EPS = 1e-9;

int main () {
    
    ll n; cin >>n;
    vector<ll> v(n); REP(i,n) cin >> v[i];

    vector<ll> cums((ll)v.size()+1, 0);
    for (ll i = 0; i < (ll)v.size(); i++) {
        cums[i+1] = cums[i] + v[i];
    }

    ll res = INFLL;
    for (ll i = 1; i < n; i++) {
        ll x = cums[i];
        ll y = cums[n] - x;
        res = min(res, abs(x-y));
    }

    cout << res << endl;
    return 0;
}
