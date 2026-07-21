#include <bits/stdc++.h>
#include<algorithm>
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
using pll = P<ll,ll>;
using tpll = TP<ll,ll,ll>;
using vpll = V<pll>;
using vst = V<str>;
using vch = V<char>;

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
#define lcm(a,b) __lcm(a,b)
#define co(a) cout<<a<<endl
#define pb(a) push_back(a)
#define pob pop_back()
#define mp make_pair
#define mt make_tuple
#define pbmp(a,b) push_back(mp(a,b))
#define subs(a,b) substr(a,b)
#define INF 1e16
#define mod 1e9+7


int main(){
  ll R,G,B,n;
  cin>>R>>G>>B>>n;
  ll x,d=0,u=mod,count=0;
  for(ll i=0;;i++){
    for(ll j=0;;j++){
      x=n-R*i-G*j;
      if(x%B==0&&x>=0){
        count++;
      }
/*      for(ll k=0;k<30;k++){
      if(x<B*((d+u)/2)){
        u=B*((d+u)/2);
      }
      if(x>B*((d+u)/2)){
        d=B*((d+u)/2);
      }
      else{
        count++;
        break;
      }
      }*/
      if(R*i+G*j>n)break;
    }
    if(R*i>n)break;
  }
  co(count);
}
