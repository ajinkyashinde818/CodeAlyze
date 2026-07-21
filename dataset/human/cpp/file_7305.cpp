#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {
  int N;
  cin >> N;

  vector<long long> a(N);
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
  }

  vector<long long> forward(N);
  for (int i = 0; i < N; ++i) {
    if (i == 0)
      forward[i] = a[i];
    else
      forward[i] = a[i] + forward[i - 1];
  }

  vector<long long> backward(N);
  for (int i = N - 1; i >= 0; --i) {
    if (i == N - 1)
      backward[i] = a[i];
    else
      backward[i] = a[i] + backward[i + 1];
  }

  long long ret = 10000000000;
  for (int i = 0; i < N - 1; ++i) {
    ret = min(ret, abs(forward[i] - backward[i + 1]));
  }

  cout << ret << endl;

  return 0;
}
