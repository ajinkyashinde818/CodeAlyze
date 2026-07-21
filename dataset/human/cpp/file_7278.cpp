#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n;
  cin >> n;
  vector<int> card(n);
  vector<ll> rui(n);
  for(int i=0; i<n; ++i){
    cin >> card[i];
    if(i) rui[i] = rui[i-1] + card[i];
    else rui[0] = card[0];
  }
  ll ans = abs(rui[n-1] - rui[0]*2);
  for(int i=1; i<n-1; ++i){
    ans = min(ans, abs(rui[n-1] - rui[i]*2));
  }
  cout << ans << endl;
}
