#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  ll count=0; 
  for(int i=0;i<n;i++) {
    cin >> a[i];
    if(a[i]<0) {
      count++;
    }
  }
  sort(a.begin(),a.end());
  ll ans=0;
  if(count%2!=0) {
    if(count<n&&abs(a[count-1])>abs(a[count])) {
      count++;
    }
    else {
      count--;
    }
  }
  for(ll i=0;i<n;i++) {
    if(count) {
      a[i]*=-1;
      count--;
    }
    ans+=a[i];
  }
  cout << ans << endl;
}
