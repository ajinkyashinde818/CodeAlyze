#include <bits/stdc++.h>
using namespace std;

int n;
int a[100001];
int b[100001];
map<int, vector<int>> ma;
map<int, vector<int>> mb;
vector<int> G[100001];
bool used[100001];

void rec(int from) {
  if (used[from]) return;
  used[from] = true;
  for (int to : G[from]) {
    rec(to);
  }
}

int cat() {
  for (auto&& p : ma) {
    int val = p.first;
    auto it = mb.find(val);
    if (it == mb.end()) continue;
    int to = it->second.front();
    for (int from : p.second) {
      G[from].push_back(to);
    }
    
    for (int i = 1; i < it->second.size(); ++i) {
      int from = it->second[i - 1];
      int to = it->second[i];
      G[from].push_back(to);
    }
  }
  
  int vertices = 0;
  int cnt = 0;
  for(int i = n; i >= 0; --i) {
    if (a[i] == b[i]) continue;
    ++vertices;
    if (used[i]) continue;
    rec(i);
    ++cnt;
  }
  return (vertices - 1) + (cnt - 1);
}

bool ok() {
  for (auto&& p : mb) {
    int val = p.first;
    int cnt = p.second.size();
    auto it = ma.find(val);
    if (it == ma.end() || it->second.size() < cnt) return false;
  }
  return true;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  int sum = 0;
  for (int i = 0; i < n; ++i) sum ^= a[i];
  a[n] = sum;
  b[n] = -1;
  for (int i = 0; i <= n; ++i) ma[a[i]].push_back(i);
  for (int i = 0; i < n; ++i) mb[b[i]].push_back(i);
  
  if (ok()) {
    cout << cat() << endl;
  } else {
    cout << -1 << endl;
  }
}
