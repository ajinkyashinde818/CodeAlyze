#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int endAOnly = 0;
int startBOnly = 0;
int both = 0;

void solve() {
  int r, g, b, n;
  cin >> r >> g >> b >> n;
  int ret = 0;
  for(int i = 0; i*r <= n; i++) {
    for(int j = 0; i*r + j*g <= n; j++) {
      int k = n-i*r-j*g;
      if(k >= 0 && k%b==0) ret++;
    }
  }
  cout << ret << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}
