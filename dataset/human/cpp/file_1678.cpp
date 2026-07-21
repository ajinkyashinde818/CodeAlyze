#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<double, double> pdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
//const int mod = ;

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  for (int k = 1; k <= 1000; ++k) {
    if (k * (k - 1) / 2 == n) {
      cout << "Yes\n" << k << endl;
      vvi s(k);
      int t = 1;
      for (int i = 0; i < k; ++i) for (int j = i + 1; j < k; ++j) {
        s[i].push_back(t);
        s[j].push_back(t);
        ++t;
      }
      for (int i = 0; i < k; ++i) {
        cout << s[i].size();
        for (int x : s[i]) cout << ' ' << x;
        cout << endl;
      }
      return 0;
    }
  }
  cout << "No\n";
  return 0;
}
