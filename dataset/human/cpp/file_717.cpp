#include <iostream>
#include <iomanip>
#include <cstdio>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
#include <string>
#include <set>
#include <random>
using namespace std;
int main() {
  int r, g, b, n;
  cin >> r >> g >> b >> n;
  int ans = 0;
  for (int i = 0; i <= n / r; i++) {
	  for (int j = 0; j <= n / g; j++) {
		  if (r * i + g * j <= n && (n - r * i - g * j) % b == 0) {
			  ans++;
			}
		}
	}
  cout << ans << endl;
  return 0;
}
