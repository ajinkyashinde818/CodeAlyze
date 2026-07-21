#include <iostream>
#include <iomanip>
#include <cstdio>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector <int> A(N);
  long long sum = 0;
  int m         = 1e9 + 1;
  int count     = 0;
  for (int i = 0; i < N; i++) {
	  cin >> A[i];
	  sum += abs(A[i]);
	  m    = min(abs(A[i]), m);
	  if (A[i] < 0) {
		  count++;
		}
	}
  cout << sum - (count % 2 == 0 ? 0 : 2 * m) << endl;
  return 0;
}
