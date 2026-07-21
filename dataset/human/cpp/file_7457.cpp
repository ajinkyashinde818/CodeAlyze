#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
using namespace std;

int main() {
  int N; cin >> N;
  int A[200010];
  for (int i = 0; i < N; i++)
    cin >> A[i];
  
  long x = A[0];
  long y = 0;
  for (int j = 1; j < N; j++)
    y += A[j];
  long ans = abs(x - y);
  for (int k = 1; k <= N - 2; k++) {
    x += A[k];
    y -= A[k];
    ans = min(ans, abs(x - y));
  }
  
  cout << ans << endl;
  return 0;
}
