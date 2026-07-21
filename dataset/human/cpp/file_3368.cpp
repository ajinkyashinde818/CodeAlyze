#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  int cnt;
  ll ans = 0;
  int mini = 1e9;
  for (int i = 0; i < n; i++){
    if (a[i] < 0) cnt++;
    ans += abs(a[i]);
    mini = min(mini, abs(a[i]));
  }
  if (cnt % 2 == 0){
    cout << ans << endl;
  } else {
    cout << ans - 2 * mini << endl;
  }
  return 0;
}
