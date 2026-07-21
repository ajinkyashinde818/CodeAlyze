//   _/                _/                 _/_/_/   _/
//_/_/_/_/   _/_/   _/_/_/_/   _/_/    _/       _/_/
// _/     _/    _/   _/     _/    _/  _/_/_/     _/
//_/     _/    _/   _/     _/    _/  _/    _/   _/
// _/_/   _/_/       _/_/   _/_/      _/_/     _/
#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const double pi=3.14159265358979323846;
const int inf=2e9;
const ll INF=5e18;
typedef pair<int,int> P;
int main() {
  cin.tie(0),cout.tie(0);
  ios::sync_with_stdio(false);
  ll n,a[200005]={},cnt=0,ans=INF,x=0;
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> a[i];
    cnt+=a[i];
  }
  for(int i=0; i<n; i++) {
    x+=a[i];
    if(i<n-1) {
      ans=min(ans,abs((cnt-2*x)));
    }
  }
  cout << ans << endl;
}
