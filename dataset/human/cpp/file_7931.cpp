#include<iostream>
#include<vector>
#include<complex>
using namespace std;
typedef long long int llint;
int main() {
	int n;
	cin >> n;
	vector<llint>a(n);
	llint x;
	for (int i = 0;i < n;i++) {
		if (i == 0) {
			cin >> a[i];
		}
		else {
			cin >> x;
			a[i] = a[i - 1] + x;
		}
	}
	llint tmp = a[n - 1];
	llint ans = 2000000000;
	for (int i = 0;i < n - 1;i++) {
		if (ans > abs(tmp - 2 * a[i])) {
			ans = abs(tmp - 2 * a[i]);
		}
	}
	cout << ans << endl;
	return 0;
}
