#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;

  int N;
  cin >> N;
  vector<int> A(N);
  int min = 999999999;
  int mini = 0;
  int count = 0;
  long long sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    if (abs(A.at(i)) < min) {
      min = abs(A.at(i));
    }
    if (A.at(i) < 0) {
      count++;
    }
    sum += abs(A.at(i));
  }
  if (count % 2 == 1) {
    sum -= 2 * abs(min);
  }
  cout << sum << endl;
}
