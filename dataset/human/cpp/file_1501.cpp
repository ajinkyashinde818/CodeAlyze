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

int main()
{
  int n;
  cin >> n;
  int k = 1;
  while (k * (k - 1) / 2 < n) k++;
  if (k * (k - 1) / 2 != n) {
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";
  cout << k << endl;
  vector<vector<int>> g(k);
  int cur = 0;
  for (int i = 0; i < k; ++i) {
    for (int j = i + 1; j < k; ++j) {
      g[i].push_back(cur);
      g[j].push_back(cur);
      cur++;
    }
  }

  for (auto v : g) {
    cout << v.size();
    for (int x : v) cout << " " << x + 1;
    cout << endl;
  }

  return 0;
}
