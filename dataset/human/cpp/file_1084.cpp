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
// #include <numeric>
using namespace std;



typedef unsigned long ul;
typedef unsigned long long ull;
typedef long long ll;
typedef vector<ll> vint;
typedef vector<vector<ll>> vvint;
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


typedef struct{
  ll pos;
  ll depth;
} data;
//
// struct Node{
//
// }



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



int main() {

  // ll N;
  // cin >> N;
  //



  ll R,G,B,N;
  cin>>R>>G>>B>>N;

  ll ans=0;

  // cout << N/R;

  rep(r, N/R+1){
    rep(g, (N-R*r)/G+1){
      if((N-R*r-G*g)%B==0) ans++;
      // rep(b, (N-R*r-G*g)/B+1){
      //   // cout << R*r+G*g+B*b<< endl;
      //   if(R*r+G*g+B*b==N){
      //     ans++;
      //   }
      // }
    }
  }


  cout << ans << endl;


}

















//
