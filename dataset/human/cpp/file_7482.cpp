#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <cmath>
#include <string>
#include <queue> 
#include <list>
#include <stack>
#include <unordered_map>
#include <algorithm> 
#include <numeric>  
#include <functional>
#include <cassert>
#include <bitset>
#include <cctype>  
#include <iomanip> 
#include <limits>  
// std::numeric_limits<int>::max(), min()
// std::setprecision(X)
// std::islower(), std::isupper(), std::tolower, std::toupper
// std::accumulate(m.begin(), m.end(), 0LL);
// std::sort(begin(),end()) // 0, 1, 2, 3 ,4 (default, less);
// std::priority_queue<int, vector<int>, less<int>> que; // 4, 3, 2, 1 (defualt, less) : 
 
#define  rep(i, n) for(int i = 0; i < (int)(n);    i++)
#define rrep(i, n) for(int i = ((int)(n)-1); i>=0; i++)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;

ll gcd ( ll a, ll b ) { if ( b == 0 ) return a; else return gcd ( b, a%b ); }
ll lcm ( ll a, ll b ) { return a * b / gcd(a, b); }

class CumulativeSum {
  private:
    std::vector<long long> s;

  public:
    explicit CumulativeSum (int N) {
      s.resize(N+1);
    }

    // s0 = 0, s1 = a0, s2 = a0 + a1, ...
    void build ( const std::vector<long long> &a ) {
      s[0] = 0;
      for(int i=1; i<s.size(); i++) s[i] = s[i-1] + a[i-1];
    }

    // Get [ i, j )
    long long Get ( int i, int j ) {
      return s[j] - s[i];
    }
};


int main (void) {
  std::cin.tie(0);  std::ios::sync_with_stdio(false);

  int N; std::cin >> N;
  std::vector<ll> a(N); rep(i,N) std::cin >> a[i];

  CumulativeSum s(N); s.build(a);
  ll ans = 1e18;
  for(int i=1; i<=N-1; i++) ans = std::min(ans,std::abs(s.Get(0,i) - s.Get(i,N)));
  std::cout << ans << std::endl;
  return 0;
}
