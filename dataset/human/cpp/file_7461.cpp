#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int N;
  cin >> N;
  vector<int64_t> memo(N);
  cin >> memo.at(0);
  for (int i = 1; i < N; i++) {
    int64_t a;
    cin >> a;
    memo.at(i) = a + memo.at(i - 1);
  }
  double ans = 100000000000001;
  for (int i = 0; i < N - 1; i++) {
    ans = min(ans, abs(((memo.at(N - 1) + 0.0) / 2) - memo.at(i)));
  }
  int64_t A = 2 * ans;
  cout << A << endl;
}
