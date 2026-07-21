#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <cstdint>
#include <cmath>
#include <bitset>
#include <string>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

#define N_TIMES(i, n)     for ( uint64_t i = 0;     i <  n; ++i )
#define N_TIMES_REV(i, n) for (  int64_t i = n - 1; i >= 0; --i )

int main(int argc, char **argv)
{
  uint64_t N;
  cin >> N;
  
  vector<int64_t> A(N);
  N_TIMES(n, N) { cin >> A[n]; }
  
  vector<int64_t> B(N);
  uint64_t C = 0;
  N_TIMES(n, N) {
    B[n] = ::abs(A[n]);
    if (A[n] < 0) { ++C; }
  }
  
  uint64_t S = accumulate(B.begin(), B.end(), static_cast<int64_t>(0), plus<int64_t>());
  uint64_t x = *min_element(B.begin(), B.end());
  
  if (C % 2 == 1) {
    S -= x << 1;
  }
  
  cout << S << endl;
  
  return 0;
}
