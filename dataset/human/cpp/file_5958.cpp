#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define repi(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define repdi(i,a,b) for(ll i=(a)-1;i>=(b);--i)
#define repd(i,a) repdi(i,a,0)
#define itr(it,a) for( auto it = (a).begin(); it != (a).end(); ++it )
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

using ll = long long;
using P = std::pair<ll, ll>;

constexpr ll INF = 1ll<<60;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<class S, class T>
std::ostream& operator<< ( std::ostream& out, const std::pair<S,T>& a )
{ std::cout << '(' << a.first << ", " << a.second << ')'; return out; }

template<class T>
std::ostream &operator<< ( std::ostream& out, const std::vector<T>& a )
{ std::cout << '['; rep( i, a.size() ){ std::cout << a[i]; if( i != a.size()-1 ) std::cout << ", "; } std::cout << ']'; return out; }

ll N, C;
ll x[100010], v[100010];
ll maL[100010], maR[100010], maLT[100010], maRT[100010];

int main()
{
  std::cin >> N >> C;

  rep( i, N )
    std::cin >> x[i] >> v[i];

  ll vS = 0;

  rep( i, N )
  {
    vS += v[i];

    maR[i+1] = std::max( maR[i], vS-x[i] );
    maRT[i+1] = std::max( maRT[i], vS-2*x[i] );
  }

  vS = 0;

  repd( i, N )
  {
    vS += v[i];

    maL[i] = std::max( maL[i+1], vS-(C-x[i]) );
    maLT[i] = std::max( maLT[i+1], vS-2*(C-x[i]) );
  }

  ll ans = 0;

  rep( i, N+1 )
  {
    chmax( ans, maR[i]+maLT[i] );
    chmax( ans, maL[i]+maRT[i] );
  }

  std::cout << ans << std::endl;

  return 0;
}
