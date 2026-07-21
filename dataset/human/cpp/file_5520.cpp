#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
const ll INF = 1LL<<60;
/*template*/

int main()
{
  ll n,r;cin>>n>>r;
  ll ans= n<10 ? r+100*(10-n):r;
  cout<<ans<<endl;
  return 0;
}
