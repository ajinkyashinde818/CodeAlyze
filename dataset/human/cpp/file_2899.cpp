#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <fstream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<P> vp;
#define rep(i,a,n) for(ll i = (a);i < (n);i++)
#define per(i,a,n) for(ll i = (a);i > (n);i--)
#define lep(i,a,n) for(ll i = (a);i <= (n);i++)
#define pel(i,a,n) for(ll i = (a);i >= (n);i--)
#define clr(a,b) memset((a),(b),sizeof(a))
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define sz size()
#define endl "\n"
#define print(X) cout << (X) << "\n"
// // #define input(X) getline(cin,X)
static const ll  INF = 1e9+7;
static const ll INFL = 1e18+7;
ll n,m,l, p;
string s,t;
ll d[200010],e[200010],dp[1001][1001];
char field[202][202];

int main(){
  cin >> n;
  ll ans = 0;
  int count = 0;
  ll mn = INF;
  rep(i,0,n){
    cin >> d[i];
    if(d[i] < 0)count++;
    mn = min(mn, abs(d[i]));
    ans += abs(d[i]);
  }
  if(count % 2)print(ans-2*mn);
  else print(ans);
  return 0;
}
