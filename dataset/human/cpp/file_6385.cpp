#include<iostream>
#include<string>
#include<cstring>
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
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
#define PI 3.141592653589793



int main(){
  int N; string S; cin >> N >> S; vector<ll> ato; ll cnt = 0, ans = 1;
  rep(i, 2*N-1){
    if(S[i]==S[i+1]) cnt++;
    if(cnt%2) ato.push_back(i+1);
  }
  if(ato.size()!=N || S[0]=='W' || S[2*N-1]=='W'){
    cout << 0 << endl; return 0;
  }
  cnt=0;
  rep(i, N){
    ato[i]-=cnt; if(ato[i]<0) ato[i]+=mod; ato[i]%=mod; ans*=ato[i]; ans%=mod; cnt+=2; cnt%=mod;
  }
  ll fact[N+100]; fact[0]=1;
  rep(i, N+50){
    fact[i+1]=fact[i]*(i+1)%mod;
  }
  ans*=fact[N]; ans%=mod;
  cout << ans << endl;  
}
