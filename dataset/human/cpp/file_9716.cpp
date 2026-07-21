#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

constexpr int MOD = 1000000007;

int main() {
  int N;
  cin >> N;
  vector<int> m(26);
  char c;
  while (cin >> c) ++m[c - 'a'];
  cout << accumulate(begin(m), end(m), 1LL,
                     [](auto a, int x) { return a * (x + 1) % MOD; }) -
              1
       << endl;
}
