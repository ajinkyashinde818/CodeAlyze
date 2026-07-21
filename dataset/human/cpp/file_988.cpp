#include<iostream>
using namespace std;

int main(void) {
	int r, g, b, n;
	int ret = 0;
	int t1, t2;
	cin >> r >> g >> b >> n;
	for (int i = 0; i * r <= n; i++) {
		t1 = i * r;
		for (int j = 0; j * g <= n - t1; j++) {
			t2 = j * g;
			int k = (n - t1 - t2) / b;
			if (t1 + t2 + k * b == n)
				ret++;
		}
	}
	cout << ret << endl;
	return 0;
}
