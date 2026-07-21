#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  ll A[N];
  ll sum = 0;
  ll small = 1000000007;
  ll nega = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    small = min(small,abs(A[i]));
    sum += abs(A[i]);
    if (A[i] < 0) {
      nega++;
    }
  }
  if (nega % 2 == 0) {
    cout << sum << endl;
  } else {
    cout << sum - (small * 2) << endl;
  }
  return 0;
}
