#include <bits/stdc++.h>
using namespace std;

int main() {
  int N = 0;
  cin >> N;
	
  bool flag_zero = false;
  bool flag_ideal = true;
  int min_abs_A = INT_MAX;
  long long int sum_abs_A = 0;
  vector<int> A(N, 0);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    sum_abs_A += abs(A[i]);
    if (A[i] == 0) {
      flag_zero = true;
    }
    if (abs(A[i]) < min_abs_A) {
      min_abs_A = abs(A[i]);
    }
    if (A[i] < 0) {
      flag_ideal = !flag_ideal;
    }
  }
  
  if ((flag_ideal || flag_zero) == true) {
    cout << sum_abs_A << endl;
  } else {
    cout << sum_abs_A - 2 * min_abs_A << endl;
  }
  
  return 0;
}
