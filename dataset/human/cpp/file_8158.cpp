#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  long long sum = 0;
  for(int i = 0; i < n; i++) {
    cin >> a.at(i);
    sum += a.at(i);
  }
  long long tmp, snuke = 0, ans = LONG_MAX;
  for(int i = 0; i < n - 1; i++) {
    snuke += a.at(i);
    tmp = sum - snuke;
    ans = min(abs(snuke - tmp), ans);
  }
  cout << ans << endl;
}
