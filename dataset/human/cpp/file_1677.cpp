#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  int x = -1, y = -1;
  for (int i = 1; i < 1000; i++) {
    if (i * (i + 1) == 2 * n) {
      x = i;
      y = i + 1;
      break;
    }
  }
  
  if (x == -1) {
    cout << "No\n";
    return 0;
  }
  
  vector<int> v[y];
  int now = 1;
  for (int i = 0; i < y - 1; i++) {
    for (int j = 0; j < x - i; j++) {
      v[i].emplace_back(now);
      now++;
    }
  }
  now = 1;
  for (int i = 1; i < y; i++) {
    for (int j = 0; j + i < y; j++) {
      v[i + j].emplace_back(now);
      now++;
    }
  }
  
  cout << "Yes\n" << y << '\n';
  for (int i = 0; i < y; i++) {
    cout << x;
    for (int j = 0; j < x; j++) {
      cout << " " << v[i][j];
    }
    cout << '\n';
  }
}
