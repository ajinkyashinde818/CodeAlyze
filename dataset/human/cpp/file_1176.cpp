#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef unsigned long ul;
typedef long long ll;
typedef pair<ul, ul> P;
map<int, int> dp;
#define REP(i, n) for (int i = 0; i < n; i++)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  vector<int> box(3, 0);
  int N;
  cin >> box[0] >> box[1] >> box[2] >> N;
  int ans = 0;
  int rest = 0;
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= N; j++) {
      rest = N - box[0] * i - box[1] * j;
      if (rest >= 0 && (rest % box[2] == 0)){
       ++ans;
      //  cout << i << " "<<j <<" " <<rest % box[2]<<endl;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
