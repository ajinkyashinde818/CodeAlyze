#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int64_t N;
  cin >> N;
  vector<int64_t> As(N+1);
  vector<int64_t> Bs(N);
  vector<int64_t> Ds(N+1);
  for (int64_t n = 0; n < N + N; ++n) {
    int64_t i;
    cin >> i;
    if (n < N) {
      ++As[i];
    } else {
      Bs[n % N] = i;
      ++Ds[i];
    }
  }
  for (int64_t n = 1; n <= N; ++n) {
    if (As[n] + Ds[n] > N) {
      cout << "No" << endl; return 0;
    }
    As[n] += As[n-1];
    Ds[n] += Ds[n-1];
  }
  cout << "Yes" << endl;
  
  int64_t mx = 0;
  for (int64_t n = 1; n <= N; ++n) {
    mx = max(mx, As[n] - Ds[n-1]);
  }
  for (int64_t n = 0; n < N; ++n) {
    if (n) cout << " ";
    cout << Bs[(n + N - mx) % N];
  }
  cout << endl;

  return 0;
}
