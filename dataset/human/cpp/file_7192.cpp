#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
  int N;
  cin >> N;
  vector< ll > as;
  ll all_sum = 0;
  for (int i = 0; i < N; i++) {
    ll a;
    cin >> a;
    all_sum += a;
    as.push_back(all_sum);
  }
  ll ans = LLONG_MAX;
  for (int i = 0; i < N-1; i++) {
    ans = min(ans, abs(2*as[i] - all_sum));
  }
  cout << ans << endl;
}
