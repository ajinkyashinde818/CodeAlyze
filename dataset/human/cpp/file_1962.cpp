#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  int N;
  cin >> N;
  vector<long long> A(N);

  long long abs_min = 2000000000;
  long long abs_sum = 0;
  int odd_count = 0;

  for (int i = 0; i < N; i++) {
    long long tmp;
    cin >> tmp;
    odd_count += (tmp < 0 ? 1 : 0);

    A[i] = tmp;

    tmp = abs(tmp);
    abs_sum += tmp;

    if (abs_min > tmp) {
      abs_min = tmp;
    }
  }

  cout << (odd_count % 2 == 0 ? abs_sum : abs_sum - 2 * abs_min) << "\n";
  return 0;
}
