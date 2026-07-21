#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
const ll inf=1e18;

int main() {
  ll n;
  cin >> n;
  vec a(n);
  ll sum=0;
  for(ll i=0;i<n;i++) {
    cin >> a[i];
    sum+=a[i];
  }
  ll ans=inf;
  ll sunuke=0;
  for(ll i=0;i<n-1;i++) {
    sum-=a[i];
    sunuke+=a[i];
    ans=min(ans,abs(sum-sunuke));
  }
  cout << ans << endl;
}
