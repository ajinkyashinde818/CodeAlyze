#include <bits/stdc++.h>
using namespace std;

int main() {

  int N;
  cin >> N;

  vector<long long> a(N);
  long long sum = 0;

  for (int i = 0; i < N; i++) {
    cin >> a[i];
    sum += a[i];
  }

  long long answer = 1LL<<60;
  long long current = 0;

  for (int i = 0; i < N - 1; i++) {
    current += a[i];
    long long c_ = sum - current;
    answer = min(abs(current - c_), answer);
  }

  cout << answer << endl;

  return 0;

}
