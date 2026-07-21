#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
   
int main() {
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	vector<string> b(m);
	rep(i, n) {
		cin >> a[i];
	}
	rep(i, m) {
		cin >> b[i];
	}
	rep(dx , n - m + 1) {
		rep(dy, n - m + 1) {
			bool is_ok = true;
			rep(x, m) {
				rep(y, m) {
					if (a[y + dy][x + dx] != b[y][x]) {
						is_ok = false;
						y = m;
						x = m;
					}
				}
			}
			if (is_ok) {
				cout << "Yes" << endl;
				return 0;
			}
		}

	}
	cout << "No" << endl;

	return 0;
}
