#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

vector<string> a, b;
int n, m;

bool check(int s_i, int s_j) {
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < m; ++j)
      if (a[s_i + i][s_j +j] != b[i][j])
        return false;
  return true;
}

int main() {
  auto start = high_resolution_clock::now();

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  a.resize(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  b.resize(m);
  for (int i = 0; i < m; ++i)
    cin >> b[i];

  for (int i = 0; i + m <= n; ++i)
    for (int j = 0; j + m <= n; ++j)
      if (check(i, j)) {
        cout << "Yes\n";
        return 0;
      }

  cout << "No\n";

  cerr << "Total execution time : " << duration_cast<milliseconds>(high_resolution_clock::now() - start).count() << " ms" << endl;

  return 0;
}
