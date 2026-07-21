#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> A(N);
  bool zero = false;
  int cnt = 0;
  long long sum = 0;
  for (int i = 0; i < N; i++) {
    int a; cin >> a;
    if (a == 0) zero = true;
    if (a < 0) cnt++;
    sum += abs(a);
    A.at(i) = abs(a);
  }
  sort(A.begin(), A.end());
  if (zero || cnt % 2 == 0) cout << sum << endl;
  else cout << sum - 2 * A.at(0) << endl;
}
