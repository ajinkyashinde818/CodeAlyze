#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n; cin >> n;
  vector<ll> a(n);
  vector<ll> s(n+1);
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++) s[i+1] += s[i] + a[i];
  ll ans = 1001001001001001;
  for(int i = 1; i < n; i++){
    ll sunuke = s[i] - s[0];
    ll arai = s[n] - s[i];
    ans = min(abs(arai - sunuke), ans);
  }
  cout << ans << endl;
}
