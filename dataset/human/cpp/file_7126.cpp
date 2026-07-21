#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <random>
#include <set>
#include <deque>
#include <queue>
#include <bitset>
#include <stack>

#define mod 1000000007
#define INF2 9999999999
#define INF (1<<30)
#define rep(i,n) for(int (i)=0; (i)<(n); (i)++)
//#define P pair<int, int>

using namespace std;
using ll = __int64_t;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int DX[] = {1, 1, 0, -1, -1, -1, 0, 1};
int DY[] = {0, -1, -1, -1, 0, 1, 1, 1};

void solve(){
  ll n;
  cin >> n;
  ll a[n], b[n], sum = 0, ans = (1<<30);
  rep(i, n) cin >> a[i], sum += a[i];
  if(n == 2){
    cout << abs(a[0]-a[1]) << endl;
    return;
  }else{
    b[0] = a[0];
    for(int i = 1; i < n-1; i++){
      b[i] = a[i]+b[i-1];
      if(abs(b[i]*2-sum) < ans){
        ans = abs(b[i]*2-sum);
      }
    }
  }
  cout << ans << endl;
}

int main(){
  solve();
  return 0;
}
