#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, c;
  cin >> n >> c;
  pair<ll,ll> mp[n];
  for (int i = 0; i < n; i++) {
    cin >> mp[i].first >> mp[i].second;
  }

  ll ans = 0;
  ll amt = 0;
  ll rec1[n], rec2[n];
  ll sum1[n], sum2[n];
  for (int i = 0; i < n; i++) {
    amt += mp[i].second;
    rec1[i] = amt - mp[i].first;
    sum1[i] = amt;
    ans = max(ans, rec1[i]);
  }
  amt = 0;
  for (int i = 0; i < n; i++) {
    amt += mp[n-1-i].second;
    rec2[i] = amt - (c - mp[n-1-i].first);
    sum2[i] = amt;
    ans = max(ans, rec2[i]);
  }
  for (int i = 1; i < n; i++) {
    rec1[i] = max(rec1[i], rec1[i - 1]);
    rec2[i] = max(rec2[i], rec2[i - 1]);
  }
  for (int i = 0; i < n - 1; i++) {
    ans = max(ans, sum1[i] - mp[i].first * 2LL + rec2[n - i - 2]);
  }
  for (int i = 0; i < n - 1; i++) {
    ans = max(ans, sum2[i] - (c - mp[n - i - 1].first) * 2LL + rec1[n - i - 2]);
  }
  cout << ans << endl;
  return 0;
}
