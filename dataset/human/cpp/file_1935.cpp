// includes {{{
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<tuple>
#include<cmath>
#include<random>
#include<cassert>
#include<bitset>
#include<cstdlib>
// #include<deque>
// #include<multiset>
// #include<cstring>
// #include<bits/stdc++.h>
// }}}
using namespace std;
using ll = long long;

int main() {
  std::ios::sync_with_stdio(false), std::cin.tie(0);

  map<char, int> mp;

  for(int i = 0; i < 10; i++) mp['0' + i] = i;
  for(int i = 0; i < 6; i++) mp['a' + i] = 10 + i;

  int q;
  cin >> q;

  cout << showpoint;
  for(int i = 0; i < q; i++) {
    string s;
    cin >> s;
    signed x = 0;
    int sgn = 1;
    for(int j = 0; j < 8; j++) {
      int v = mp[s[j]];
      if(j == 0 && (v & 8)) {
        v ^= 8;
        sgn = -1;
      }
      x += v << ((7 - j) * 4);
    }
    double ans = sgn * (double(x) / (1 << 7));
    stringstream ss;
    // ss << showpoint;
    ss << fixed << setprecision(10);
    ss << ans;
    string g;
    ss >> g;
    while(g[g.size()-1] == '0' && g[g.size()-2] != '.') g.pop_back();
    cout << g << "\n";
  }

  return 0;
}
