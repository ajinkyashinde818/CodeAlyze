#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <map>
#include <numeric>
#include <random>
#include <queue>
#include <deque>
#include <tuple>
#include <iomanip>
#include <iterator>
#include <functional>

using namespace std;
typedef long long ll;

const int INF = (1 << 30) - 1;
const ll INFLL= (1LL << 61) - 1;
const int MOD = 1000000007;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin>>N;
  vector<ll>A(N),sum(N+1);
  REP(i,N)cin>>A[i];
  REP(i,N){
    sum[i+1]=sum[i]+A[i];
  }

  ll ans=INFLL;
  FOR(i,1,N){
    ans=min(ans,abs(sum[i]-(sum[N]-sum[i])));
  }

  cout<<ans<<endl;
}
