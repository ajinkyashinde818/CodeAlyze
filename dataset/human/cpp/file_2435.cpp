#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  int cnt = 0, mi = 2e9;
  long sum = 0;
  for (int i = 0; i < N; i++) {
    if (A.at(i) < 0) cnt++;
    mi = min(mi, abs(A.at(i)));
    sum += abs(A.at(i));
  }
  cout << ((cnt % 2) ? sum - mi * 2 : sum) << "\n";
}
