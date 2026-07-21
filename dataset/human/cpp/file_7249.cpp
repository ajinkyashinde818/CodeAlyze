#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main(){
  int N;
  cin >> N;
  ll a[N];
  for(int i=0;i<N;i++) cin >> a[i];
  ll sum[N+1];
  sum[0] = 0LL;
  for(int i=1;i<=N;i++) sum[i] = sum[i-1] + a[i-1];

  ll ans = 1000000000000000;
  for(int i=0;i<N-1;i++){
    ll x,y;
    x = sum[i+1];
    y = sum[N] - sum[i+1];
    ans = min(ans, abs(x-y));
  }

  cout << ans << endl;
  return 0;
}
