#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
  ll n,m;
  cin >> n >> m;
  vector<string> a(n);
  vector<string> b(m);
  for(ll i=0;i<n;i++) {
    cin >> a[i];
  }
  for(ll i=0;i<m;i++) {
    cin >> b[i];
  }
  for(ll i=0;i<n-m+1;i++) {
    for(ll j=0;j<n-m+1;j++) {
      bool flag=true;
      for(ll k=j;k<j+m;k++) {
        if(a[k].substr(i,m)!=b[k-j]) {
          flag=false;
        }
      }
      if(flag) {
      cout << "Yes" << endl;
      return 0;
      }
    }
  }
  cout << "No" << endl;
}
