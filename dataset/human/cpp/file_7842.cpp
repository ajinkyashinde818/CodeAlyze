#include <iostream>
#include <vector>
#include <numeric>
#include <climits>
using namespace std;
 
int main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i=0; i<n; ++i) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	long snuke_ = accumulate(v.begin(), v.end(), (long) 0);
	long raccoon = 0;
	long res = LONG_MAX;
	for (int i=n-1; i>0; --i) {
		int a = v[i];
		snuke_ -= a;
		raccoon += a;
		res = min(res, abs(snuke_-raccoon));
	}
	cout << res << endl;
}
