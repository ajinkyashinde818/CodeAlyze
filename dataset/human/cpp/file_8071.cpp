#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint INF = 1e18;

signed main(){
  lint N; cin >> N;
  lint sum = 0;
  vector<lint> rui(N + 1, 0);
  for(lint i = 0; i < N; i++){
    lint a; cin >> a; sum += a;
    rui[i + 1] = rui[i] + a;
  }
  lint ans = INF;
  for(lint i = 1; i < N; i++) ans = min(ans, abs(rui[i] - (sum - rui[i])));
  cout << ans << endl;
}
