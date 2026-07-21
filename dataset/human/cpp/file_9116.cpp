#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n), b(m);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < m; i++) {
    cin >> b[i];
  }
  for(int i = 0; i < n - m + 1; i++) {
    for(int j = 0; j < n - m + 1; j++) {
      int num = 0;
      while(num + i < n && a[num + i].substr(j, m) == b[num]) {
        num++;
      }
      if(num == m) {
        cout << "Yes\n";
        return 0;
      }
    }
  }
  cout << "No\n";
  return 0;
}
