#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool f[200010];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  
  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  iota(a.rbegin(), a.rend(), 1);
  
  for (int i = 0; i < m; i++) {
    int e;
    cin >> e;
    a.push_back(e);
  }
  reverse(a.begin(), a.end());
  
  for (int i = 0; i < a.size(); i++) {
    if (f[a[i]]) continue;
    f[a[i]] = true;
    cout << a[i] << endl;
  }

  return 0;
}
