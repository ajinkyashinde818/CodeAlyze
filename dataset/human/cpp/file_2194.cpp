#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int a[n];
  int minus = 0;
  int AT[n];
  long ans = 0;
  bool zero = 1;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    if(a[i] < 0) minus++;
    ans += abs(a[i]);
    AT[i] = abs(a[i]);
    if(a[i] == 0) zero = 0;
  }
  if(zero) {
    if(minus % 2 == 1) {
      sort(AT, AT + n);
      ans -= 2 * AT[0];
    }
  }
  cout << ans << endl;
  return 0;
}
