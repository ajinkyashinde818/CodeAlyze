#include <iostream>
#include <cstdlib>
using namespace std;
typedef long long ll;
int main(void) {
  int n;
  cin >> n;
  ll a[200000];
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  ll sunuke = 0;
  ll answer = abs(sum - a[0] * 2);
  for (int i = 0; i < n - 1; i++) {
    sunuke += a[i];
    if (abs(sum - sunuke * 2) < answer) {
      answer = abs(sum - sunuke * 2);
    }
  }
  cout << answer << endl;
  return 0;
}
