#include <iostream>
#include <iosfwd>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <cctype>
#include <climits>
#include <vector>
#include <bitset>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <deque>
#include <string>
#include <list>
#include <iterator>
#include <sstream>
#include <complex>
#include <fstream>
#include <functional>
#include <numeric>
#include <utility>
#include <algorithm>
#include <assert.h>
#include <unordered_map>

using namespace std;
const int N = 1e6 + 50;
const long long mod = 1e9 + 7;
const long long INF = 1LL << 57;
const int LN = 22;
const int SN = 320;

long long n, m, u, v, k, t, q, x, d, p, a, b, c, s;


string str;

int main() {
   ios::sync_with_stdio(false);cin.tie(0);
   cin >> n;
   cin >> str;
   long long sol = 1;
   int open = 0;
   for (int i = 0; i < str.size(); ++i) {
      if (i % 2 == 0 and str[i] == 'W') {
         sol = (sol * open) % mod;
         open--;
         if (open < 0) open = 0;
      } else if (i % 2 == 0 and str[i] == 'B') {
         open++;
      } else if (i % 2 == 1 and str[i] == 'W') {
         open++;
      } else {
         sol = (sol * open) % mod;
         open--;
         if (open < 0) open = 0;
      }
   }
   
   if (open != 0) cout << 0 << endl;
   else {
      for (int i = 1; i <= n; ++i) {
         sol = (sol * i) % mod;
      }
      cout << sol << endl;
   }
}
