#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
using namespace std;
typedef long long ll;
int main(){
  ll n = 0;
  cin >> n;
  vector<ll> num(n);
  ll all = 0;
  for(int i = 0;i <= n - 1;i++){
    cin >> num[i];
    all += num[i];
  }
  ll res = 0;
  res = INT_MAX;
  ll now = 0;
  for(int i = 0;i <= n - 2;i++){
    now += num[i];
    res = min(res,max(all - now,now) - min(all - now,now));
  }
  cout << res << endl;
  return 0;
}
