#include <bits/stdc++.h>
       
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
  int N, R;
  cin >> N >> R;
  int ans = R;
  if (N <= 10) ans += 100 * (10 - N);
  cout << ans << endl;
  return 0;
}
