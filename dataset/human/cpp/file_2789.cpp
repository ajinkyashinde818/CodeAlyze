#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {
  long long N;
  cin >> N;

  long long a[N];
  long long total = 0;
  long long n_neg = 0;
  long long minimum = 100000000000LL;
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
    total += abs(a[i]);
    if (a[i] < 0)
      ++n_neg;
    minimum = min(minimum, abs(a[i]));
  }

  if (n_neg % 2 == 0)
    cout << total << endl;
  else {
    total -= 2 * minimum;
    cout << total << endl;
  }

  return 0;
}
