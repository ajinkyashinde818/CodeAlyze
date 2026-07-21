#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	bool flip=0;
	int min = 1000000000;
	long long sum = 0;
	for (int i = 0, a; i < n; i++) {
		cin >> a;
		if (a < 0) {
			flip ^= 1;
			a = -a;
		}
		sum += a;
		if (a < min)
			min = a;
	}
	if (flip) {
		sum -= min * 2;
	}
	cout << sum << endl;
}
