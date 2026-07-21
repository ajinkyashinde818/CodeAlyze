#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const double eps = 1e-10;
const int MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<50;

template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}

int main () {
  cin.tie(0);
  cout << fixed << setprecision(10);

  int r, g, b, n; cin >> r >> g >> b >> n;
  int cnt = 0;
  for(int i=0;i<=n/r;++i) {
    for(int j=0;j<=n/g;++j) {
      if((n - i * r - j * g) % b == 0 && (n-i*r-j*g)/b >= 0) {
        // cout << i << ":" << j << ":" << (n-i*r-j*g)/b << endl;
        cnt++;
      }
    }
  }
  cout << cnt << endl;
}
