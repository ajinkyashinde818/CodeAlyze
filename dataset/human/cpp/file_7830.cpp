#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
using namespace std;

void solve(){
  int n; cin >> n;
  vector<int> a(n);
  long long sum = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    sum += a[i];
  }
  long long x = a[0], y = sum - a[0];
  long long ans = abs(x - y);
  for(int i = 1; i < n - 1; i++){
    x += a[i];
    y -= a[i];
    ans = min(abs(x - y), ans);
  }
  cout << ans << endl;
  return;
}

int main(){
  solve();
  return 0;
}
