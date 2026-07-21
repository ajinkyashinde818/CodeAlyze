#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

using std::max;
using std::pair;
using std::vector;

typedef long long ll;

int main()
{
  int n;
  std::cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    std::cin >> v.at(i);
  }
  vector<pair<ll, ll>> memo(n);
  memo.at(1).first = v.at(0) + v.at(1);
  memo.at(1).second = -v.at(0) - v.at(1);
  for (int i = 2; i < n; i++) {
    memo.at(i).first = max(memo.at(i-1).first, memo.at(i-1).second) + v.at(i);
    memo.at(i).second = max(memo.at(i-1).first - 2*v.at(i-1), memo.at(i-1).second + 2*v.at(i-1)) - v.at(i);
  }
  std::cout << max(memo.at(n-1).first, memo.at(n-1).second) << '\n';
  return 0;
}
