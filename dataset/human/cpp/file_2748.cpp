#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) {
    cin >> A.at(i);
  }

  ll ans = 0; // 絶対値の合計
  for (ll i = 0; i < N; i++){
    ans += abs(A.at(i));
  }

  int minus_cnt = 0; // 負数の数を数える
  for (ll i = 0; i < N; i++) {
    if (A.at(i) < 0) minus_cnt++;
  }
  
  if (minus_cnt % 2 != 0) { // 負数が奇数個ならどれか一つ-が残るので、絶対値が一番小さいものを負にする
    ll min = abs(A.at(0));
    for (ll i = 1; i < N; i++) {
      if (abs(A.at(i)) < min) min = abs(A.at(i));
    }
    ans -= abs(min) * 2;
  }
  
  cout << ans << endl;
}
