#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
int main(){
  ll n;
  cin>> n;
  vll a(n);
  ll sum=0,count=0,min=1000000000;
  for (ll i=0;i<n;i++) {
    cin >> a[i];
    sum+=abs(a[i]);
    if (a[i]<0) {
      count++;
    }
    if (min>abs(a[i])) {
      min=abs(a[i]);
    }
  }
  
  ll ans;
  if (count%2==0) {
    ans=sum;
  }
  else {
    ans=sum-2*min;
  }
  
  cout << ans;
}
