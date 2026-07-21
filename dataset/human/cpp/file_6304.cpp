#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll mod=1e9+7;

vector<ll> tfact(1e7+1);
void fact(ll n) {
  for(ll i=0;i<=n;i++) {
    if(i==0) {
      tfact[i]=1;
    }
    else {
      tfact[i]=tfact[i-1]*i%mod;
    }
  }
}

int main() {
  ll n;
  string s;
  cin >> n >> s;
  n*=2;
  vector<ll> d(n);
  d[0]=-1;
  for(ll i=0;i<n-1;i++) {
    if(s[i]==s[i+1]) {
      d[i+1]=-d[i];
    }
    else {
      d[i+1]=d[i];
    }
  }
  if(s[0]=='W'||s[n-1]=='W'||d[n-1]==-1) {
    cout << 0 << endl;
    return 0;
  }
  ll l=1;
  ll ans=1;
  for(ll i=1;i<n;i++) {
    if(d[i]==1) {
      ans=ans*l%mod;
      l--;
      if(l<0) {
        cout << 0 << endl;
        return 0;
      }
    }
    else {
      l++;
    }
  }
  fact(n/2);
  ans=ans*tfact[n/2]%mod;
  if(ans<0||l!=0) {
    ans=0;
  }
  cout << ans << endl;
}
