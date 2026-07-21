#include <iostream>
#include <string>
#include <map>
#include <cmath>

using namespace std;

long long fact(long long x, int life) {
  if (life == 0)
    return 1;
  else if (x == 1)
    return 1;
  else
    return (x * fact(x - 1, life - 1)) % 1000000007;
}

int main(int argc, char* argv[]) {
  int N;
  cin >> N;

  string s;
  cin >> s;

  map<char, int> m;
  for (int i = 0; i < N; ++i) {
    if (m.find(s[i]) == m.end())
      m[s[i]] = 0;
    ++m[s[i]];
  }

  long long ret = 1;
  for (map<char, int>::iterator i = m.begin(); i != m.end(); ++i) {
    ret *= i->second + 1;
    ret %= 1000000007;
  }

  cout << ret - 1 << endl;

  return 0;
}
