#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<memory.h>

using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
  ll n;
  cin >> n;
  ll a[n];
  rep(i,n)cin >> a[i];
  ll sum=0;
  rep(i,n)sum+=a[i];
  ll ans=abs(2*a[0]-sum);
  ll temp=a[0];
  for(int i=1;i<n-1;i++){
    temp+=a[i];
    ans=min(ans,abs(2*temp-sum));
  }
  cout << ans << endl;
return 0;}
