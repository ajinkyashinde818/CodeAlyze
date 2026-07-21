#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
 
/*** Template Begins ***/
 
typedef long long    ll;
typedef pair<ll,ll>  pll;
typedef pair<ll, pair<int, int> > plll;
typedef vector<long long>  vll;
typedef vector<pll>  vp;
typedef long double ld;
#define pb           push_back
#define INF          INT_MAX/10
#define F            first
#define S            second
#define mp           make_pair
// #define ios          ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define hell         1000000007
// #define h 998244353
#define all(a)       (a).begin(),(a).end()
ll power(ll x, ll y, ll p)
{
  ll res = 1;
  x = x % p;
  while (y > 0)
  { 
    if (y & 1) 
      res = (res*x) % p;
    y = y>>1;
    x = (x*x) % p;
  } 
  return res; 
} 
const int MAXN = 1e5+7;

// Debug //
#define trace(x)                 cerr << #x << ": " << x << endl;
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
// #define trace6(a, n,i;b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Constants //
 
/*** Template Ends ***/
ld euclid(ld x,ld y,ld i,ld j)
{
  return sqrt(abs(x*x-i*i)+abs(y*y-j*j));
}
void solve()
{
 ll n,r;
 cin>>n>>r;
 if(n>=10)
  cout<<r;
  else
    cout<<r+100*(10-n);
}
int main()
{ 
  // ios;
  // fxreopen("inputt.txt", "w", stdout);
  ll t;
  // cin >> t;
  t=1;
  while(t--)
    solve();
  return 0;
}
