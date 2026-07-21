#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <functional>
#include <bitset>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <numeric>
#define ll long long int
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int mx4[] = {0,1,0,-1};
int my4[] = {1,0,-1,0};
int INF = 2e6;
 
 
int main(){
  int n; cin >> n;
  ll ans = 3e9;
  vector<ll> a(n),s(n);
  rep(i,n) cin >> a[i];
  s[0] = a[0];
  rep(i,n-1) s[i+1] = s[i] + a[i+1];
  rep(i,n-1) ans = min(ans,abs(s[n-1]-2 * s[i]));
  cout << ans << endl;
}
