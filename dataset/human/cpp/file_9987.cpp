#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

const int mod = 1e9 + 7;

int main(int argc, char* argv[])
{
  using std::cin;
  using std::cout;
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  std::string s;
  cin >> s;

  std::map<char, int> cnt;
  for (char c : s) cnt[c]++;

  long long res = 1;
  for (auto& entry : cnt)
  {
    res *= (entry.second + 1);
    res %= mod;
  }
  res = (res - 1 + mod) % mod;
  cout << res << "\n";

  return 0;
}
