#include <assert.h>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
 
using ll = long long;
using P = std::pair<long double, ll>;
 
#define rep(i, a, b) for (ll(i) = (a); i < (b); i++)
#define all(i) i.begin(), i.end()
#define debug(i) std::cerr << "debug " << i << std::endl
 
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, std::pair<T1, T2> pa) {
  return os << pa.first << " " << pa.second;
}
 
template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> vec) {
  for (int i = 0; i < vec.size(); i++)os << vec[i] << (i + 1 == vec.size() ? "" : " ");
  return os;
}
 
template<typename T1,typename T2>
inline bool chmax(T1& a,T2 b){return a<b && (a=b,true);}
 
template<typename T1,typename T2>
inline bool chmin(T1& a,T2 b){return a>b && (a=b,true);}

template<typename T>
T pow_mod(T a, long long b) {
  if (a == 0) {
    return 0;
  }
 
  T x = 1;
 
  while (b > 0) {
    if (b & 1) {
      x = (x * a);
    }
    a = (a * a);
    b >>= 1;
  }
  return x;
}
 
// const ll MOD = 998244353;
const ll MOD = 1e9 + 7;
 
struct Circle{
  long double x,y,r;
};
 
int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  Circle s,t;

  std::cin>>s.x>>s.y>>t.x>>t.y;

  s.r=0;t.r=0;

  ll n;
  std::cin>>n;

  std::vector<Circle> circles(n+2);

  circles[0]=s;
  circles[n+1]=t;

  rep(i,0,n){
    long double x,y,r;
    std::cin>>x>>y>>r;
    circles[i+1]={x,y,r};
  }

  std::vector<long double> d(n+2,-1);
  d[0]=0;

  std::priority_queue<P,std::vector<P>,std::greater<P>> que;

  que.push({0,0});

  while(!que.empty()){
    P p=que.top();
    que.pop();

    ll v=p.second;

    if(d[v]<p.first)continue;

    rep(i,0,n+2){
      if(i!=v){
        long double cost=sqrtl(pow_mod(circles[i].x-circles[v].x,2)+pow_mod(circles[i].y-circles[v].y,2))-circles[i].r-circles[v].r;
        chmax(cost,0);
        if(d[i]==-1||d[i]>d[v]+cost){
          d[i]=d[v]+cost;
          que.push({d[i],i});
        }
      }
    }
  }

  std::cout<<std::setprecision(10)<<std::fixed<<d[n+1]<<"\n";

  return 0;
}
