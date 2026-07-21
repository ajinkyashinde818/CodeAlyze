#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for(int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  set<pair<int, int>> same;
  for(int i = 0; i < n; ++i) {
    if(a[i] == b[i]) {
      same.insert({a[i], i});
    }
  }
  while(same.size() && same.begin()->first != same.rbegin()->first) {
    assert(same.size() >= 2);
    swap(b[same.begin()->second], b[same.rbegin()->second]);
    same.erase(same.begin());
    same.erase(prev(same.end()));
  }
  if(same.size()) {
    int x = same.begin()->first;
    vector<int> free;
    for(int i = 0; i < n; ++i) {
      if(a[i] != x && b[i] != x) free.push_back(i);
    }
    if(same.size() > free.size()) {
      cout << "No\n";
      return 0;
    }
    for(auto [x_, i] : same) {
      swap(b[i], b[free.back()]);
      free.pop_back();
    }
  }
  cout << "Yes\n";
  for(int i = 0; i < n; ++i) {
    cout << b[i] << ' ';
  }
  cout << '\n';
}
