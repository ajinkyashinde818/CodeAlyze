#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <climits>
#include <math.h>
#include <utility>
#include <ctime>
#include <cstdlib>
using namespace std;

typedef long long ll;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<char>> vvc;
typedef vector<vector<bool>> vvb;
typedef vector<vector<int>> vvi;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define all(a) a.begin(),a.end()

int main() {
	int n, m; cin >> n >> m;
	vs a(n), b(m);
	rep(i, n) {
		cin >> a.at(i);
	}
	rep(i, m) {
		cin >> b.at(i);
	}
	bool ok = true;
	rep(i, n - m + 1) {
		rep(j, n - m + 1) {
			ok = true;
			rep(k, m) {
				rep(l, m) {
					if (a.at(i + k).at(j + l) != b.at(k).at(l)) {
						ok = false;
						break;
					}
				}
			}
			if (ok) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
