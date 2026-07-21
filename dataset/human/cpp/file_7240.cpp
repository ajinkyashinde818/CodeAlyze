#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int n;  cin >> n;
  vector<ll> a(n);
  for(int i=0; i<n; i++)  cin >> a.at(i);
  vector<ll> sum(n+1, 0);
  for(int i=1; i<=n; i++)
    sum.at(i) = a.at(i-1)+sum.at(i-1);
  
  ll ans = 1e+15;
  for(int i=1; i<n; i++)
    ans = min(ans, abs(sum.at(i)-(sum.at(n)-sum.at(i))));
  cout << ans << endl;
}
