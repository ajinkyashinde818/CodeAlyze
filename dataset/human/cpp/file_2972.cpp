#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

int N, A[1<<20], neg = 0, minm = 1e9;
long long sum = 0;

int main() {
  //freopen("input.in","r",stdin);
  //freopen("output.out","w",stdout);

  cin >> N;
  for(int i = 0;i < N;i++) {
    cin >> A[i];
    sum += abs(A[i]);
    if(A[i] < 0) neg++;
    minm = min(minm, abs(A[i]));
  }

  cout << (((neg % 2) == 0) ? sum : (sum - 2*minm)) << endl;

  return 0;
}
