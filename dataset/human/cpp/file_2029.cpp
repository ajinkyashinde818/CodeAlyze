#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int min = 1E+9 + 100;
	int mncount = 0;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		ans += abs(a);
		if (abs(min) > abs(a)) min = a;
		if (a < 0) mncount++;
	}
	if (mncount & 1) cout << ans - 2 * abs(min) << endl;
	else cout << ans << endl;
}
