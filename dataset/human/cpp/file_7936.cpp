#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <cmath>
using namespace std;
#define MOD 1000000007
#define INF 1<<30
#define LINF 1LL<<62
#define MAX 510000
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> P;
typedef vector<pair<ll, ll>> vpl;
const int mod = 1e9 + 7;

int main(){
    ll n; cin >> n;
    vl a(n);
    rep(i,n) cin >> a[i];
    vl sum(n+1,0);
    rep(i,n) sum[i+1] = sum[i] + a[i];
    vl dist(n);
    rep(i,n-1){
        dist[i] = abs(sum[n] - sum[i+1] - sum[i+1]);
    }
    ll ans = LINF;
    rep(i,n-1) ans = min(dist[i],ans);
    cout << ans << endl;
}
