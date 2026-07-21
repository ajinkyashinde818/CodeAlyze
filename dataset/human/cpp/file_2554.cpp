// Add compile option "-std=c++11" for C++11 compile.

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <regex>
#include <numeric>
using namespace std;

// Macro
#define rep(i, N) for(int i=0; i<(int)N; i++)

// Type
template <typename T> using P = pair<T, T>;
using ll = long long;
using ull = unsigned long long;

// Constants
const ll INF = 1e18;
const ll MOD = 1000000007;

int main() {
  int N;
  cin >> N;

  ll abs_sum = 0;   // 絶対値の総和
  ll abs_min = INF; // 絶対値の最小値
  int minus_n = 0;  // マイナス値の数
  bool zero_flag = false; // 0があるか
  rep(i, N) {
    ll A;
    cin >> A;

    if(A == 0) {
      zero_flag = true;
      continue;
    }

    if(A < 0) {
      minus_n++;
    }

    ll abs_A = abs(A);
    abs_sum += abs_A;
    abs_min = min(abs_min, abs_A);
  }

  if(zero_flag || minus_n % 2 == 0) {
    cout << abs_sum << endl;
  } else {
    cout << abs_sum - (2 * abs_min) << endl;
  }
}
