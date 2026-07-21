#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  long long ans = 0;
  int cnt_minus = 0;
  int cnt_0 = 0;
  int min_abs = 1e9;
  for (int i=0; i<n; i++) {
    int a;
    cin>>a;
    ans += abs(a);
    if (a == 0) {
      ++cnt_0;
    } else if (a < 0) {
      ++cnt_minus;
    }
    min_abs = min(min_abs, abs(a));
  }

  if (cnt_minus % 2 == 1 && cnt_0 == 0) {
    ans -= 2 * min_abs;
  }
  cout<<ans<<endl;
}
