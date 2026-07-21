#include <iostream>
#include <stdint.h>
#include <vector>
#include <limits.h>
#include <utility>

using namespace std;

int main()
{
  int64_t N;
  cin >> N;

  int64_t sum = 0;
  int64_t min_abs = INT64_MAX;
  int64_t minus_count = 0;
  
  for (int n=0; n<N; ++n) {
    int64_t a;
    cin >> a;
    if (a < 0) {
      ++minus_count;
      a = -a;
    }

    sum += a;

    if (a < min_abs)
      min_abs = a;
  }

  if (minus_count%2)
    sum -= 2*min_abs;
  
  cout << sum << endl;
  
  return 0;
}
