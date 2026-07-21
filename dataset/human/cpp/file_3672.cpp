#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
const ll INF = 1LL<<60;

int main() {
  ll N;
  cin >> N;
  ll cnt = 0LL;
  vector<ll> v(N);
  for(ll i = 0; i < N; i++) {
    cin >> v.at(i);
    if(v.at(i)<0) cnt++;
  }
  ll ans = 0LL;
  if(cnt % 2==0){
    for(ll i = 0; i< N; i++) {
      ans += abs(v.at(i));
    }
  }
  else {
    ll neg=INF;
    for(ll i = 0LL; i < N; i++) {
      chmin(neg, abs(v.at(i)));
      ans += abs(v.at(i));
    }
    ans -= 2LL*neg;
  }
  cout << ans << endl;
}
