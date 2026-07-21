#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <climits>
using namespace std;



int main() {
  int N;
  cin >> N;

  long long a;
  vector<long long> sum(N+1, 0);
  for (int i = 1; i <= N; ++i) {
    scanf("%lld", &a);
    sum[i] = sum[i-1] + a;
  }

//  for (int i = 1; i <= N; ++i) {
//    cout << sum[i] << endl;
//  }

  long long diff = LONG_LONG_MAX;
  for (int i = 1; i < N; ++i) {
    long long x = sum[i];
    long long y = sum[N] - sum[i];
    diff = min(diff, abs(x - y));
//    cout << x << " " << y << " " << diff << endl;
  }

  cout << diff << endl;

  return 0;
}
