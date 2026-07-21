#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int abs(int n) {
  if (n < 0) {n = -n;}
  return n;
}

int main() {
  int N; 
  cin >> N;
  ll a[N];
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  vector<P> v;
  
  for (int i = 0; i < N; i++) {
    v.push_back(P(abs(a[i]), a[i]));
  }
  sort(v.begin(), v.end());
  
  int flag = 0;
  ll ans = 0;
  for (int i = N-1; i > 0; i--) {
    if (v[i].second < 0) {flag++;}
    ans += v[i].first;
  }
  
  if (flag % 2 == 0) {ans += v[0].second;}
  else {ans -= v[0].second;}
  
  cout << ans << endl;
}
