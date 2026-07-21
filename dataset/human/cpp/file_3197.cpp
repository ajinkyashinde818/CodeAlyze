#include <iostream>

using namespace std;
typedef long long ll;
const int MAXN = 1e5+10;
const ll INF = 1e10;

int n;
ll a[MAXN];

void solve() {
  int cntMinus = 0;
  ll minimum = INF;
  ll sum = 0;
  for (int i=0;i<n;i++) {
    if (a[i] < 0) {
      cntMinus++;
    }
    sum += abs(a[i]);
    minimum = min(abs(a[i]), minimum);
  }
  if (cntMinus & 1) {
    sum -= minimum * 2;
  }
  cout << sum << endl;
}

int main() {
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> a[i];
  }
  solve();
}
