#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> solve() {
  int N; cin >> N;
  int sz = 0;
  for (int i = 1; i * (i+1) / 2 <= N; i++) {
     if (i * (i+1) / 2 == N) sz = i + 1;
  }
  if (!sz) return vector<vector<int>>(0);
  vector<vector<int>> v(sz);
  int cnt = 1;
  for (int i = 0; i < sz; i++) {
    for (int j = i+1; j < sz; j++, cnt++) {
      v[i].push_back(cnt);
      v[j].push_back(cnt);
    }
  }
  return v;
}

int main() {
  auto res = solve();
  if (res.size()) {
    cout << "Yes" << endl << res.size() << endl;
    for (auto& v : res) {
      cout << v.size();
      for (auto x : v) {
        cout << " " << x;
      }
      cout << endl;
    }
  } else {
    cout << "No" << endl;
  }
}
