// #include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <map>
#include <math.h>
#include <algorithm> // std::sort, std::min, std::next_permutation, std::lower_bound
#include <iomanip> // std::setprecision
#include <cmath> // std::ceil
#include <numeric> // std::gcd, std::lcm
#include <limits> // std::numeric_limits<long int>::max()
#include <unordered_map>
#include <map>
#include <cmath> // std::atan2
#include <deque>
#include <queue>

using namespace std;
typedef long long ll;
#define INF 1999999999
#define MODA 1000000007 
#define rep(i,n) for (long long i = 0; i < (n); ++i)

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];

  ll sum = 0;
  ll count = 0;
  ll m = numeric_limits<ll>::max();
  rep(i, N) {
    if(A[i] < 0) count++;
    ll absA = abs(A[i]);
    sum += absA;
    m = min(m, absA);
  }
  if(count%2 == 1) {
    sum -= 2 * m;
  }
  cout << sum << endl;
  return 0;
}
