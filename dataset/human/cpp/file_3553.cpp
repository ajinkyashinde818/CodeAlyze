#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cctype>
#include <numeric>

using namespace std;

#define REP(i,n) for(ll (i) = (0); (i) < (n); ++i)
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define ALL(v) v.begin(),v.end()
#define Decimal fixed << setprecision(20)
#define SHOWP(x) cerr<<"["<<(x).FI<<", "<<(x).SE<<"]";
#define SHOWX(x) cerr<<#x<<": "<<x<<endl;
#define SHOWVEC(v, e) REP(i, e) cerr << (v[i]) << ' '; cerr << endl;
#define SHOW2D(a, h, w) REP(i, h){REP(j, w)cerr<<setw(3)<<(a[i][j])<<' ';cerr<<endl;}
constexpr int INF = 1 << 30 - 1;
constexpr long long LLINF = 1LL << 60;
constexpr long long MOD = 1000000007;

typedef long long ll;
typedef pair<ll, ll> P;


int main()
{
  int N;
  cin >> N;
  vector<ll> A(N);
  REP(i, N) cin >> A[i];
  vector<ll> B(A);
  REP(i, N) B[i] = abs(B[i]);
  REP(i, N - 1) {
    if (A[i] < 0) {
      A[i] *= -1;
      A[i + 1] *= -1;
    }
  }

  ll ans = 0;
  REP(i, N) ans += B[i];
  if (A.back() < 0) {
    ans -= 2*(*min_element(ALL(B)));
  }
  cout << ans << endl;
  
  return 0;
}
