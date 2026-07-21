#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long int ll;
const ll LINF = 1e18;
int main(int argc, char const *argv[]) {
  ll N;
  cin >> N;
  vector<ll> a(N);
  ll sum = 0;
  for (size_t i = 0; i < a.size(); i++) {
    cin >> a[i];
    sum += a[i];
  }
  ll sunuke = 0;
  ll araiguma = sum;
  ll ans = LINF;
  for (size_t j = 0; j < a.size()-1; j++) {
    sunuke += a[j];
    araiguma -= a[j];
    if (ans > abs(sunuke - araiguma)) {
      ans = abs(sunuke - araiguma);
    }
  }
  cout << ans << endl;

  return 0;
}
