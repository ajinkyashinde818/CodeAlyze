#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <utility>
using namespace std;
typedef unsigned long ulong;

class Solver {

public:
	static void solve() {
		int t, d;
		cin >> t >> d;
		int ta, tb;
		cin >> ta >> tb;
		int da, db;
		cin >> da >> db;

		double res = 1000;

		for (int i = 0; da * i <= d; i++) {
			int delta = d - da * i;
			for (int j = 0; db * j <= delta; j++) {
				if (i == j && i == 0)continue;

				double tTemp = 1.0 * (ta * da * i + tb * db * j) 
					/ (da * i + db * j);
				res = min(res, abs(t - tTemp));
			}
		}

		cout << res;
	}

};

int main() {
	Solver::solve();
	return 0;
}
