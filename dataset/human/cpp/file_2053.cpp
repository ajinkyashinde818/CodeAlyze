#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
  int N; cin >> N;

  vector<int> A(N);

  bool isZero = false;
  int num_minus = 0;
  int min_abs = numeric_limits<int>::max();
  unsigned long max_total = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    if (A[i] == 0) {
      isZero = true;
    } else if (A[i] < 0) {
      num_minus++;
    }
    min_abs = min(min_abs, abs(A[i]));
    max_total += abs(A[i]);
  }

  if (!isZero && (num_minus%2 == 1)) {
    max_total -= 2*min_abs;
  }

  cout << max_total << endl;
  return 0;
}
