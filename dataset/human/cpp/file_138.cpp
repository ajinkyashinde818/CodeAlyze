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
  int r,g,b,n;
  cin >> r >> g >> b >> n;
  int ans = 0;
  for(int i = 0; i <= 3000; i++) for(int j = 0; j <= 3000; j++) {
    int k = n - i * r - g * j;
    if(k >= 0 && k % b == 0) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
