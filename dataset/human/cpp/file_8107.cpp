#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n,ans;
  cin >> n;
  ll a[n];
  ll sum[n];
  cin >> a[0];
  sum[0] = a[0];
  for(int i = 1;i < n;i++){
    cin >> a[i];
    sum[i] = sum[i-1] + a[i];
  }
  for(int i = 0;i < n-1;i++){
    if(i == 0)ans = abs(sum[n-1]-2*sum[i]);
    else ans = min(ans,abs(sum[n-1]-2*sum[i]));
  }
  cout << ans << endl;
}
