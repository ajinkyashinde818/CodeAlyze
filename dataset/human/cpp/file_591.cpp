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
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
 
int main(){
  int r,g,b,n;
  cin >> r >> g >> b >> n;
  int ans=0;
  rep(i,n+1){
    rep(j,n+1){
      if(n-i*r-j*g>=0 && (n-i*r-j*g)%b==0){
        ans++;
      }
    }
  }
  cout << ans << endl;
return 0;}
