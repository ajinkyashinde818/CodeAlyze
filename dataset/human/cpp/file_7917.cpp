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
#include <tuple>
#include <complex>
#include <cassert>
#include <exception>
#include <iomanip>
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
#define print(X) cout << (X) << "\n"
static const int INF = 1e+18+7;
int n,m,l;
int p;
string s,t;
ll d[200010],dp[300][300];
char field[200][200];

int main(){
  cin >> n;
  lep(i,1,n){
    cin >> d[i];
    d[i] += d[i-1];
  }
  // lep(i,0,n)print(d[i]);
  ll ans = INF;
  rep(i,1,n){
    ans = min(ans,abs(2 * d[i] - d[n]));
  }
  print(ans);
  return 0;
}
