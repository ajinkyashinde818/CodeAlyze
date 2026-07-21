#include <bits/stdc++.h>
using namespace std;

int main() {
  long N;
  cin >> N;
  long long ans = 0, mini, count = 0;
  long long temp;
  cin >> temp;
  ans += abs(temp);
  if (temp < 0) count++;
  mini = abs(temp);
  for (int i = 1; i < N; i++) {
    cin >> temp;
    ans += abs(temp);
    if (temp < 0) count++;
    mini = min(mini, abs(temp));
  }
  if (count % 2 == 1) ans -= 2 * mini;
  cout << ans;
  return 0;
}
