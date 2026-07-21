#include <bits/stdc++.h>

using namespace std;

void Run() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  for (int i = 0; i < n; ++i)
    cin >> b[i];
  vector<int> freqA(n + 1);
  vector<int> freqB(n + 1);
  set<pair<int, int> > cnt;
  for (int i = n - 1; i >= 0; --i) ++freqA[a[i]];
  for (int i = n - 1; i >= 0; --i) ++freqB[b[i]];
  for (int i = 1; i <= n; ++i) {
    if (freqB[i]) {
      cnt.emplace(freqA[i], i);
    }
  }
  vector<int> res(n, -1);
  for (int pos = 0; pos < n; ++pos) {
    if (cnt.empty()) {
      cout << "No\n";
      return;
    }
    auto it = cnt.find(make_pair(freqA[a[pos]], a[pos]));
    bool found = (it != cnt.end());
    if (found) {
      cnt.erase(it);
    }
    if (cnt.empty()) {
      cout << "No\n";
      return;
    }
    auto p = *cnt.rbegin();
    res[pos] = p.second;
    cnt.erase(p);
    if (--freqB[p.second] > 0) {
      cnt.insert(p);
    }
    if (found) {
      cnt.emplace(--freqA[a[pos]], a[pos]);
    }
  }
  for (int i = 1; i <= n; ++i) {
    assert(freqB[i] == 0);
  }
  cout << "Yes\n";
  for (int i = 0; i < n; ++i) {
    cout << res[i] << " ";
  }
  cout << "\n";
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  Run();
  return 0;
}
