#include<iostream>
using namespace std;

int main() {
	int sum = 0;
	int r, g, b; cin >> r >> g >> b;
	int n; cin >> n;
	int i=0, j=0;
	for (i = 0; i <= n / r ; i++) {
		for (j = 0; j <= n / g; j++) {
			if ((n-i * r - j * g) % b == 0 && 0 <= (n-i * r -j * g) / b) { sum = sum + 1; }
		}
	}
	cout << sum;
	return 0;
}
