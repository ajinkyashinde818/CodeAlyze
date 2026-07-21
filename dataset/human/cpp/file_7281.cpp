#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll n,x=0;
  cin >> n;
  vector<ll> a(n),b(n),c(n),d(n-1);
  for(ll i=0;i<n;i++){
    cin >> a.at(i);
    x += a.at(i);
  }
  
  b.at(0) = 0;
  c.at(0) = x;
  for(ll i=1;i<n;i++){
    b.at(i) = a.at(i-1) + b.at(i-1);
    c.at(i) = x - b.at(i);
  }
  for(ll i=0;i<n-1;i++){
    d.at(i) = max(b.at(i+1) -c.at(i+1),c.at(i+1) -b.at(i+1));
  }
  sort(d.begin(),d.end());
  cout << d.at(0) << endl;
  
  return 0;
}
