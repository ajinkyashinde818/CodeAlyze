#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
  int N;
  cin >> N;
  long long minVal = __INT_MAX__;
  long long ans = 0;
  int count = 0;
  for (int i=0;i<N;i++) {
    long long a;
    cin >> a;
    if (a < 0) {
      a *= -1;
      count = 1 - count;
    }
    if (a < minVal) minVal = a;
    ans += a;
  }
  if (count) ans -= (minVal*2);
  cout << ans << endl;
  return 0;
}
