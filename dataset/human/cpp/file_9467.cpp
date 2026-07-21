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
#include <unordered_set>

using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,ll> pll;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
  int n,m;
  cin >> n >> m;
  char a[n][n],b[m][m];
  rep(i,n)rep(j,n)cin >> a[i][j];
  rep(i,m)rep(j,m)cin >> b[i][j];
  rep(i,n)rep(j,n){
    if(i+m>n || j+m>n)continue;
    bool flag=true;
    rep(k,m)rep(l,m)if(a[i+k][j+l]!=b[k][l])flag=false;
    if(flag){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
return 0;}
