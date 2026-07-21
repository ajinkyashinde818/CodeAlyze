//code by lynmisakura.wish to be accepted!
/****************************/
#include<iostream>
#include<math.h>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<algorithm>
#include<bitset>
#include <climits>
#include<set>
#include<bitset>
using namespace std;
/***************************/
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<pair<int,int>> vpi;
 
const long long MOD = 998244353;
const long long mod = 1000000007;
const long long INF = 10000000000000;
 
#define itn int
#define endl "\n"
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define mins(x,y) x = min(x,y)
#define maxs(x,y) x = max(x,y)
#define all(x) (x).begin(),(x).end()
#define Rep(n) for(int i = 0;i < n;i++)
#define rep(i,n) for(int i = 0;i < n;i++)
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )
 
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll qp(ll a, ll b) { ll ans = 1; do { if (b & 1)ans = 1ll * ans*a; a = 1ll * a*a; } while (b >>= 1); return ans; }
ll qp(ll a, ll b, int mo) { ll ans = 1; do { if (b & 1)ans = 1ll * ans*a%mo; a = 1ll * a*a%mo; } while (b >>= 1); return ans; }
 
#define _GLIBCXX_DEBUG
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
//mint
struct mint {
   //this library is created by snuke.
  ll x; // typedef long long ll;
  mint(ll x=0):x(x%mod){}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
 
  // for prime mod
  mint inv() const {
    return pow(mod-2);
  }
  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res/=a;
  }
};

int main(void){
   int n;cin >> n;
   string s;cin >> s;
   
   //偶数番目の要素を反転させる
   rep(i,2*n-1){
      if(i%2==0){
         if(s[i] == 'W')s[i] = 'B';
         else s[i] = 'W';
      }
   }
   
   mint ans = 1;
   mint count = 0;
   int c = 0;
   rep(i,2*n){
      if(s[i] == 'W')c+=1;
      else c-=1;
   }
   if(c != 0){cout << 0 << endl;return 0;}
   rep(i,2*n){
      if(s[i] == 'W')c+=1;
      else{ans *= (mint)c;c--;}
   }
   mint f = 1;
   rep(i,n){
      f*=(mint)(i+1);
   }
   ans *= f;
   cout << ans.x << endl;
   return 0;
}
