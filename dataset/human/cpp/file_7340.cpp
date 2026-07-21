#include <iostream>

using namespace std;
typedef long long ll;
const int MAXN = 200010;
int n;
ll a[MAXN];
ll sum[MAXN];

void solve() {
  sum[0] = a[0];
  for (int i=1;i<n;i++) {
    sum[i] = sum[i-1] + a[i];
  }

  ll minimum = 1e11;
  for (int i=1;i<n;i++) {
    minimum = min(minimum, abs(2 * sum[i-1] - sum[n-1]));
  }
  cout << minimum << endl;
}

int main() {
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> a[i];
  }
  solve();
}
