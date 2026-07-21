#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  vector<int> a(n), b(n), count(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
    count.at(a.at(i))++;
  }
  for (int i = 0; i < n; i++) {
    cin >> b.at(i);
    count.at(b.at(i))++;
  }
  
  for (int i = 1; i <= n; i++) {
    if (count.at(i) > n) {
      cout << "No\n";
      return 0;
    }
  }
  
  reverse(b.begin(), b.end());
  
  int left = 1e9, right = -1, same;
  for (int i = 0; i < n; i++) {
    if (a.at(i) == b.at(i)) {
      left = i;
      same = a.at(i);
      break;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (a.at(i) == b.at(i)) {
      right = i;
      break;
    }
  }
  
  int it = 0;
  for (int i = left; i <= right; i++) {
    while (true) {
      if (a.at(it) != same && b.at(it) != same) {
        swap(b.at(it), b.at(i));
        it++;
        break;
      }
      else {
        it++;
      }
    }
  }
  
  cout << "Yes\n";
  for (int i = 0; i < n; i++) {
    if (i) cout << " ";
    cout << b.at(i);
  }
  cout << '\n';
}
