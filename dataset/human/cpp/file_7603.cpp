#include<iostream>
#include<cstdlib>
using namespace std;
int main() {
	long  int n;
	cin >> n;
	long int ans = 2000000000;
	long int s = 0;
	long int ar = 0;
	long int a[200000] = {};
	for (long  int i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
	}
 
	for (long  int i = 0; i < n-1; i++) {
		ar += a[i];
		s -= a[i];
		if (abs(ar - s) < ans) {
			ans = abs(ar - s);
		}
	}
	cout << ans << endl;
 
	return 0;
}
