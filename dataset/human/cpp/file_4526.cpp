#include <algorithm>
#include <numeric>
#include <map>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int T, D, ta, tb, da, db;
  cin >> T >> D >> ta >> tb >> da >> db;
  double res = 1e9;
  for (int i = 0; i < 1000; i++) {
	for (int j = 0; j < 1000; j++) {
	  int d = i * da + j * db;
	  if (1 <= d && d <= D) {
		double temp = (double)(ta * i * da + tb * j * db) / d;
		res = min(res, abs(T - temp));
	  }
	}
  }
  cout << res << endl;
}
