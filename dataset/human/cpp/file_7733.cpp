#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll N; cin >> N;
  vector<ll> a(N);
  ll sum = 0;
  for(ll i = 0; i < N; i++){
    cin >> a[i];
    sum += a[i];
  }
  
  
  ll su = a[0];
  ll ans = abs(sum - 2 * su);
  for(ll i = 1; i < N-1; i++){
    su+=a[i];
    ans = min(ans, abs(sum - 2 * su));
  }
  cout << ans;
}
