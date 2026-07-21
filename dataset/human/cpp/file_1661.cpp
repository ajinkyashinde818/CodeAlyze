// includes {{{
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<tuple>
#include<cmath>
#include<random>
#include<cassert>
// }}}
// #include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  std::ios::sync_with_stdio(false), std::cin.tie(0);
  int n;
  cin >> n;
  int x = 2;
  while(1) {
    if(x * (x - 1) / 2 >= n) {
      if(x * (x - 1) / 2 == n) {
        cout << "Yes\n" << x << "\n";
        vector<vector<int>> v(x);
        int cnt = 0;
        for(int i = 0; i < x; i++) for(int j = i + 1; j < x; j++) {
          cnt++;
          v[i].emplace_back(cnt);
          v[j].emplace_back(cnt);
        }
        for(int i = 0; i < x; i++) {
          cout << v[i].size();
          for(int j = 0; j < v[i].size(); j++) {
            cout << " " << v[i][j];
          }
          cout << "\n";
        }
      } else {
        cout << "No\n";
      }
      return 0;
    }
    x++;
  }
  return 0;
}
