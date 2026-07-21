#include<bits/stdc++.h>
using namespace std;

int main(){

  long long int n, a[111111];
  long long int ans = 0;
  long long int cnt = 0;
  long long int p = 1<<30;

  cin >> n;
  for(long long int i=0;i<n;i++){
    cin >> a[i];
    ans += abs(a[i]);
    if(a[i] < 0) cnt++;
    p = min(p, abs(a[i]));
  }

  //cout << cnt << " " << ans << " " << p << endl;

  if(cnt%2 == 1) ans -= 2*p;


  cout << ans << endl;

}
