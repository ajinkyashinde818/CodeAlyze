#include <iostream>
#include <string>
using namespace std;
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <set>
#include <map>
#define MOD1 1000000007
#define MOD2 998244353
#define LIMIT1 200010
#define LIMIT2 500010
#define LIMIT3 1000010
#define INF ((1<<30)-1)
#define LLINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef long double ld;
typedef const void cv;
typedef pair<ll,ll> P;
#define rep(i,n) for((i)=0;(i)<(n);(i)++)
#define per(i,n) for((i)=(n)-1;(i)>=0;(i)--)
template<class T,class C> T max(T a,C b){ return ((a)>(T)(b) ? (a) : (T)(b)); }
template<class T,class C> T min(T a,C b){ return ((a)<(T)(b) ? (a) : (T)(b)); }
#define zt(a,b) (max((a),(b))-min((a),(b)))
#define setpre(n) fixed << setprecision(n)
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[8]={1,0,-1,0,1,-1,-1,1},dy[8]={0,1,0,-1,1,1,-1,-1};
int upint(cv *a, cv *b) { return *(int *)a < *(int *)b ? -1 : *(int *)a > *(int *)b ? 1 : 0; }
int downint(cv *a, cv *b) { return *(int *)a < *(int *)b ? 1 : *(int *)a > *(int *)b ? -1 : 0; }
int upchar(cv *left, cv *right) {return strcmp((char *)left,(char *)right);}
int downchar(cv *left, cv *right) {return strcmp((char *)right,(char *)left);}
ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1){
      res *= a; if(mod>=1) res %= mod;
    }
    a *= a; if(mod>=1) a %= mod;
    n >>= 1;
  }
  return res;
}
void initialize(){
  
}
int main(void){
  initialize();
  ll m,i,j,k,result=0;
  int n;
  int a[LIMIT2]={0},b[LIMIT1]={0};
  int c[LIMIT1]={0};
  map<int,int> dp1,dp2;
  string s;
  
  cin >> n;
  m=1;
  bool ng=false;
  rep(i,n){
    cin >> a[i];
    
    dp1[a[i]]++;
    c[a[i]]++;//個数
  }
  rep(i,n){
    cin >> b[i];
    
    dp2[b[i]]++;
    c[b[i]]++;//個数
    
    if(c[b[i]]>=n+1) ng=true;
  }
  if(ng){
    cout << "No" << endl;
    return 0;
  }
  result=1;
  j=0;
  
  auto itr = dp2.begin();
  rep(i,n){
    while(itr!=dp2.end() && a[i]==itr->first) itr++;
    if(itr==dp2.end()){
      itr = dp2.begin();
      while(itr!=dp2.end() && a[i]==itr->first) itr++;
      if(itr==dp2.end()){
        itr = dp2.begin();
        b[i] = itr->first;
        while(a[i]==b[j]) j++;
        std::swap(b[i],b[j]);
        j++;
        continue;
      }
    }
    //cout << itr->first << " " << itr->second << endl;
    b[i] = itr->first;
    dp2[b[i]] -= 1;
    if(dp2[b[i]]<=0){
      itr++;
      dp2.erase(dp2.find(b[i]));
      if(itr==dp2.end()) itr=dp2.begin();
    }
  }
  
  cout << (result==1 ? "Yes" : "No") << endl;
  if(result == 1){
    rep(i,n){
      cout << b[i] << (i==n-1 ? '\n' : ' ');
    }
  }
  return 0;
}
