#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <climits>
#include <math.h>
using namespace std;

typedef long long ll;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<bool>> vvb;
typedef vector<vector<int>> vvi;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define all(a) a.begin(),a.end()

int main() {
	int n;
	cin >> n;
	vi a(n);
	vll sum(n);
	rep(i, n) {
		cin >> a.at(i);
		if (i == 0) {
			sum.at(i) = a.at(i);
		}
		else {
			sum.at(i) = sum.at(i - 1) + a.at(i);
		}
	}
	ll s = 0 , r = 0;
	ll ans = LLONG_MAX;
	ll tmp;
	rep(i, n - 1) {
		s = sum.at(i);
		r = sum.at(n - 1) - sum.at(i);
		tmp = abs(s - r);
		if (ans > tmp)ans = tmp;
	}
	cout << ans << endl;
	return 0;
}
