#include<iostream>
using namespace std;

int main(void) {
	int r, g, b, n, sum = 0;
	cin >> r >> g >> b >> n;
	for (int i = 0; r*i <= n; i++) {
		for (int j = 0; r*i + g * j <= n; j++) {
			int k = n - r * i - g * j;
			if (k%b == 0)sum++;
		}
	}
	cout << sum << endl;
	return 0;
}
