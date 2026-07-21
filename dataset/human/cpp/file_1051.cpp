#include <iostream>
#include <string>
#include <math.h>
using namespace std;


int main() {
	int n;
	int r, g, b;
	cin >> r >> g >> b >> n;
	int ans = 0;
	int a, c;
	a = (n - n % r) / r;
	for (int i = a; i >= 0; i--) {
		int x;
		x = n - r * i;
		c = (x - x % g) / g;
		for (int j = c; j >= 0; j--) {
			int y;
			y = x - g * j;
			if (y%b == 0) ans++;
			else;
		}
	}
	cout << ans << endl;
	return 0;
}
