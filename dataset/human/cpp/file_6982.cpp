#include <bits/stdc++.h>
using namespace std;
template<class C>constexpr int sz(const C&c){return int(c.size());}
using ll=long long;constexpr const char nl='\n',sp=' ';
 
int main() {
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  // freopen("err.txt", "w", stderr);
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  for (auto &&a : A) cin >> a;
  for (auto &&b : B) cin >> b;
  int mx = INT_MIN;
  for (int i = 0; i < N; i++) mx = max(mx, int(upper_bound(B.begin(), B.end(), A[i]) - B.begin() - i));
  if (mx < 0) mx += N;
  rotate(B.begin(), B.begin() + mx, B.end());
  for (int i = 0; i < N; i++) if (A[i] == B[i]) {
    cout << "No" << nl;
    return 0;
  }
  cout << "Yes" << nl;
  for (int i = 0; i < N; i++) cout << B[i] << " \n"[i == N - 1];
  return 0;
}
