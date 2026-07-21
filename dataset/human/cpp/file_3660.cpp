#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <string>
#include <bitset>
#include <functional>
#include <set>
#include <map>
#include <array>

using namespace std;
typedef long long int ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(obj) (obj).begin(), (obj).end()
#define debug(x) cout << #x << ": " << x << endl
#define int long long int
const int MOD = 1000000007;
const int INF = 100100100;
const double EPS = 0.000000001;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool pairCompare(const P& pair1, const P& pair2) {
    return pair1.second > pair2.second;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, A[100001];
  int dp[100001][2] = {};
  cin >> N;
  REP(i, N){
    cin >> A[i];
  }
  dp[0][0] = A[0];
  dp[0][1] = -A[0];
  REP(i, N-1){
    dp[i+1][0] = max(dp[i][0] + A[i+1], dp[i][1] - A[i+1]);
    dp[i+1][1] = max(dp[i][0] - A[i+1], dp[i][1] + A[i+1]);
  }
  int ans = dp[N-1][0];
  cout << ans << endl;
  return 0;
}
