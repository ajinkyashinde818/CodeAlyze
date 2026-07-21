#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <numeric>

using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  
  int num_negs = 0;
  for (int i = 0; i < N; ++i) {
    if (A[i] < 0) ++num_negs;
  }

  vector<long long> B(N);
  for (int i = 0; i < N; ++i) {
    B[i] = abs(A[i]);
  }

  long long sum = 0;
  for (int i = 0; i < N; ++i) {
    sum += B[i];
  }

  if (num_negs % 2 == 0) {
    cout << sum << endl;
  }
  else {
    sort(B.begin(), B.end());
    cout << sum - 2 * B[0] << endl;
  }
  
  return 0;
}
