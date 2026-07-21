#include <iostream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 1<<15;
const ll MOD = 1e9+7;
const double EPS = 1e-9;


int main(int argc, const char * argv[]) {
  int N; cin >> N;
  vector<ll> A(N);
  int negnum = 0;
  bool zero = false;
  for (int i=0; i<N; i++) {
    cin >> A[i];
    if (A[i] < 0) {
      negnum++;
      A[i] = -A[i];
    }
    if (A[i] == 0) zero = true;
  }
  ll ans = accumulate(A.begin(), A.end(), 0LL);
  if (not zero && negnum%2 == 1){
    sort(A.begin(), A.end());
    ans -= 2*A[0];
  }
  cout << ans << endl;
  return 0;
}
