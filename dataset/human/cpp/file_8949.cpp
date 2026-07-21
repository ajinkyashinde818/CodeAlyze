#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <tuple>
#include <stack>
#include <bitset>
#include <utility>
#include<iomanip>
// #include <numeric>
using namespace std;



typedef unsigned long ul;
typedef unsigned long long ull;
typedef long long ll;
typedef vector<ll> vint;
typedef vector<vector<ll>> vvint;
typedef vector<string> vstring;
typedef vector<vector<string>> vvstring;
typedef vector<char> vchar;
typedef vector<vector<char>> vvchar;
typedef vector<long double> vdouble;
typedef vector<vector<long double>> vvdouble;
typedef vector<vector<vector<long double>>> vvvdouble;
typedef pair<ll,ll> pint;
typedef vector<pint> vpint;

#define rep(i,n) for(ll i=0;i<n;i++)
#define repf(i,f,n) for(ll i=f;i<n;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define INT_MAX 2147483647
#define LLONG_MAX 9223372036854775807
#define vmax(vec) *max_element(vec.begin(), vec.end())
#define vmin(vec) *min_element(vec.begin(), vec.end())
#define vsort(vec) sort(vec.begin(), vec.end())
#define vsortgr(vec) sort(vec.begin(), vec.end(), greater<ll>())
#define DIVIDER 1000000007


//
// struct Node{
//   vint children;
//   ll index;
//   ll prop;
// };
// struct edge{ll to; ll cost;};



int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0,};

// ll X,Y,Z,K;
// ll pmax = 30000000000;
// vint A,B,C;




// int binary_search(int key){
//  //isOKを満たす要素のうち最小のインデックスを返す。（要ソート）
//   int left = -1;
//   int right = N;
//
//   while(right - left > 1){
//     int mid = left + (right - left)/2;
//
//     if(isOK(mid, key)) right=mid;
//     else left=mid;
//   }
//
//   return right;
// }

// ll gcd(ll m, ll n){
//   if(m<n) swap(m,n);
//   if(n==0) return m;
//   return gcd(n, m%n);
// }

// ll get_pow(ll x, ll y){
//   ll ret=0;
//   ll temp = y;
//   while(true){
//     if(x<=temp) break;
//     ret++;
//     temp *= 2;
//   }
//   return ret;
// }






int main() {
  cout<<fixed<<setprecision(10);


  ll N,M;cin>>N>>M;
  vstring A(N);rep(i,N)cin>>A[i];
  vstring B(M);rep(i,M)cin>>B[i];

  bool match;
  bool ans = false;

  rep(i,N-M+1){
    rep(j,N-M+1){
      match = true;
      // cout<<"Start"<<endl;
      rep(k,M){
        match = match && (A[i+k].substr(j,M) == B[k]);
        // cout << A[i+k].substr(j,M) << endl;
      }
      ans = ans || match;
      // cout << endl;

    }
  }

  if(ans) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;

  // cout << ans << endl;
}

















//
