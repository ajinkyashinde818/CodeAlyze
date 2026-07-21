#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include <limits>
#include <algorithm>
#include <map>
#include <sstream>
#include <unordered_map>

using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
static ull tenq = 1000000000;
static ull mod = tenq + 7;

using namespace std;

int main()
{
  ll N;
  cin >> N;
  vector<ll> as(N);
  ll sum = 0;
  for (auto i = 0; i < N; i++) {
    cin >> as[i];
    sum += as[i];
  }

  ll lsum = 0;
  ll min_diff = LONG_LONG_MAX;
  for (auto i = 0; i < N-1; i++) {
    lsum += as[i];
    ll diff = abs(lsum - (sum - lsum));
    min_diff = min(min_diff, diff);
  }

  cout << min_diff << endl;

  return 0;
}
