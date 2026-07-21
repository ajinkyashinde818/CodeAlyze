#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

const ll MODULO = 1e9 + 7;

int main()
{
  int n;
  string s;
  cin >> n >> s;
  vll c(26);
  for (int i = 0; i < n; ++i) c[s[i] - 'a']++;
  ll result = 1;
  for (int i = 0; i < 26; ++i) result = result * (c[i] + 1) % MODULO;
  result = (result + MODULO - 1) % MODULO;
  cout << result << endl;

  return 0;
}
