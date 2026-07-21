#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
#include <queue>
#include <cstdio>
using namespace std;

template <class T> using V = vector<T>;
template <class S, class T> using P = pair<S, T>;
template <class... T> using TP = tuple<T...>;

using ll = long long;
using db = double;
using ldb = long db;
using str = string;
using vll = V<ll>;
using vvll = V<V<ll>>;
using vvvll = V<V<V<ll>>>;
using pll = P<ll,ll>;
using tpll = TP<ll,ll,ll>;
using vpll =V<pll>;
using vvpll = V<vpll>;
using vtpll = V<tpll>;
using vst = V<str>;
using vch = V<char>;
using vvch = V<vch>;
using dqll = deque<ll>;
using vdqll = V<dqll>;
using pqll = priority_queue<ll>;
using pqpll = priority_queue<pll>;
using vpqll = V<pqll>;

#define FOR(i,a,b) for(ll i=(a);i<(ll)(b);i++)
#define rFOR(i,a,b) for(ll i=(b);i>(ll)(a);i--)
#define oFOR(i,a,b) for(ll i=(a);i<(ll)(b);i+=2)
#define bgn begin() 
#define en end()
#define SORT(a) sort((a).bgn,(a).en)
#define REV(a) reverse((a).bgn,(a).en)
#define fi first
#define se second
#define sz size()
#define gcd(a,b) __gcd(a,b)
#define co(a) cout<<a<<endl
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define ba back()
#define fr front()
#define pob pop_back()
#define pof pop_front()
#define mp make_pair
#define mt make_tuple
#define pbmp(a,b) push_back(mp(a,b))
#define subs(a,n) substr(a,n)
#define cfs(a) cout<<fixed<<setprecision(a) //
/*vvll v(n,vll(m)) n行m列  continue
A.erase(A.begin()+i); 配列Aのi番目を消せる
std::binary_search(v.bgn,v.en,a); 二分探索
abs(a,b)   pow(a,n)  to_string  stoll
auto Iter=lower_bound(v.bgn,v.en,a); v[i]>=aとなる初のv[i]
v.insert(lower_bound(v.bgn,v.en,a),b); bを入れられる
lower upper  co(*Iter) co(Iter-v.bgn) v[i]>=aとなる初のi
vvll v(100001,vll(0)); v[a].pb(b); v[b].pb(a);
pqll pq; pq.push(ai); pq.top(); pq.pop();
pqpll q; pll p; q.push(mp(ai,i)); p=q.top();
priority_queue<ll,vll,greater<ll>> pqg; 昇順
vdqll dq(3);  dq[0].pb(1); dq[0].pb(2); dq[0].pf(0);
dq[0].fr→0 dq[0].ba→1 dq[0].pof; dq[0].fr→1
while(que.sz) while(!que.empty()) 
ll a=1,b=2,c=4,xo; xo=a^b^c; if(a^b^c==0)co(xo)→7(miss) if(xo==0)co(xo)→なし
a<<b→a*2^b a>>b→a/2^b
rep(i,1<<10)rep(j,10)if((i>>j)&1)→iの二進で1となる桁のjのみ 
*/

const int MAX = 510000;
const int MOD = 1000000007;
long long fac[MAX], finv[MAX], inv[MAX];
void Comuse() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
#define comuse Comuse()
ll combi(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
ll pow_mod(ll a,ll n,ll mod){
  ll res=1;        //n=k_2  pow(a,k_2)
  for(;n>0;n/=2){  //ex,pow(a,1011_2)=a^8*a^2*a^1
    if(n%2==1)res=(res*a)%mod;
    a=(a*a)%mod;
  }
  return res;
}
ll digit_sum(ll n) {
  ll m=0;
  FOR(i,0,20){
    m+=n%10;
    n/=10;
    if(n==0)break;
  }
  return m;
}
ll lcm(ll a,ll b){
  ll n;
  n=a/gcd(a,b)*b;
  return n;
}

int main(){
  ll n;
  cin>>n;
  str s;
  cin>>s;
  str st;
  FOR(i,0,2*n){
    if(i%2==0){
      if(s[i]=='B'){
        st+='L';
      }
      else{
        st+='R';
      }
    }
    else{
      if(s[i]!='B'){
        st+='L';
      }
      else{
        st+='R';
      }
    }
  }
  ll c=0,bns=1;
  FOR(i,0,2*n){
    if(st[i]=='L'){
      c++;
    }
    else{
      bns*=c;
      bns%=MOD;
      c--;
    }
  }
  if(bns<0||c!=0)bns=0;
  comuse;
  ll ans=bns*fac[n]%MOD;
  co(ans);
}
