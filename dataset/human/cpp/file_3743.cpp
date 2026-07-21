#include <iostream>
using namespace std;

int main() {
  int N;
  int a[100010];
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  int min = abs(a[0]);
  int minus_count = 0;
  long sum_abs = 0;
  for(int i = 0; i < N; i++) {
    sum_abs += abs(a[i]);
    if (min > abs(a[i])) {
      min = abs(a[i]);
    }
    if(a[i] < 0) {
      minus_count++;
    }
  }

  if (minus_count % 2 == 1) {
    sum_abs -= 2 * min;
  }
  cout << sum_abs << endl;

  return 0;
}
