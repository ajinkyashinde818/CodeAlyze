#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <time.h>
#include <list>
#include <bitset>

using namespace std;
typedef long long ll;
template<class T=ll> 
T in(){T x;cin>>x;return (x);}
template<class T> 
void print(T &x){cout<<x<<"\n";}
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define reps(x,c) for(auto x:c)
#define all(x) begin(x), end(x)
#define pb(a) emplace_back(a) 
#define mp(a,b) make_pair((a),(b))
#define pl pair<ll,ll>
#define INF 2147483600
#define MOD 1000000007
#define fi first
#define se second
#define dbg(x) cerr << #x"="<< (x) << "\n"
#define dbgv(x) cerr<<#x<<"\n";reps(y,x){cerr<<y<<" ";}cerr<<"\n"

int main(){
  ll n=in(),total=0;
  vector<ll> a(n);  
  rep(i,n){
    scanf("%lld",&a[i]);
    total+=a[i];
  }
  ll snuke=0,ans=INF;
  rep(i,n-1){
    snuke+=a[i];
    ans=min(ans,abs(2*snuke-total));
  }
  print(ans);
  return 0;
}
