//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
 
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <assert.h>
#include <memory.h>
#include <time.h>
#include <bitset>
#include<iomanip>
 
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define repb(i, r, l) for (int i = (r); i > (l); i--)
#define sz(a) (int)a.size()
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)
#define mt(a,b,c) make_tuple(a,b,c)
#define rank qwertyuio
#define next dfghjk
#define plus fsghsf
#define minus ytryr
#define pb push_back
using namespace std;
 
inline bool setmin(int &x, int y) { return (y < x) ? x = y, 1 : 0; }
inline bool setmax(int &x, int y) { return (y > x) ? x = y, 1 : 0; }
inline bool setmin(ll &x, ll y) { return (y < x) ? x = y, 1 : 0; }
inline bool setmax(ll &x, ll y) { return (y > x) ? x = y, 1 : 0; }
 
const int N = 100000;
const int inf = (int)1e9 + 1;
const ll big = (ll)1e18 + 1;
const int P = 239;
const int P1 = 31;
const int P2 = 57;
const int MOD = (int)1e9 + 7;
const int mod = (int)1e9 + 7;
const int MOD1 = (int)1e9 + 9;
const int MOD2 = 998244353;
const ld eps = 1e-12;
const double pi = atan2(0, -1);
const int ABC = 26;
#define ent '\n'
ll fac[100007];
ll power(ll x, ll y) 
{ 
    ll res = 1;      // Initialize result 
  
    x = x % mod;  // Update x if it is more than or 
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % mod; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % mod; 
    } 
    return res; 
} 
ll modInverse(ll n) 
{ 
    return power(n, mod-2); 
} 
  

ll nCrModPFermat(ll n, ll r) 
{ 
   // Base case 
   if (r==0) 
      return 1; 
  
    return (fac[n]* modInverse(fac[r]) % mod * 
            modInverse(fac[n-r]) % mod) % mod; 
} 
bool sortbyfirst(const tuple<int, int, int>& a,  
               const tuple<int, int, int>& b) 
{ 
    return (get<0>(a) < get<0>(b)); 
} 
//ll power2[100005];

int main(){
    int n,r;
    cin>>n>>r;
    if(n>=10){
        cout<<r;
    }
    else{
        cout<<r+100*(10-n);
    }
}
