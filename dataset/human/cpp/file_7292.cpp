#include <iostream>
#include <climits>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <tuple>
#include <unordered_set>
#include <unordered_map>

typedef long long ll;
using namespace std;

int main(void) {
  ll N; cin >> N;
  ll sum = 0;
  vector<ll> A(N);
  for (int i = 0; i < N; i++) { cin >> A[i]; sum += A[i]; }
  // sort(A.begin(), A.end());

  ll csum = 0;
  ll ans = LONG_MAX;
  for (int i = 0; i < N; i++) {
    csum += A[i];
    if (i + 1 < N) {
      ans = min(ans, abs(sum - 2 * csum));
    }
  }
  // ll csum = 0;
  // for (int i = 0; i < N - 1; i++) {
  //   csum += A[i];
  //   if (csum + A[i + 1] > sum / 2)
  //     break;
  // }
  // ll ans = abs(csum - (sum - csum));
  cout << ans << endl;
}
