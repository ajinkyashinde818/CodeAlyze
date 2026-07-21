#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <cmath>
#include <cctype>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int main(void){
  int n;
  cin >> n;

  int neg = 0;
  LL sum = 0;
  LL min_ = 1000000000;
  bool zero = false;

  for(int i=0; i < n; i++) {
    LL tmp;
    cin >> tmp;
    if (tmp < 0) neg ++;
    if (tmp == 0) zero = true;
    sum += abs(tmp);
    min_ = min(abs(tmp), min_);
  }

  if (neg % 2 == 0) cout << sum << endl;
  else if (zero) cout << sum << endl;
  else cout << sum - 2 * min_ << endl;

  return 0;
}
