#include<iostream>

using namespace std;

typedef long long ll;

int main() {
	int n, cnt = 0, mi = 1000000000;
	ll sum = 0;
	cin >> n;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		cnt += (x < 0);
		sum += abs(x);
		mi = min(mi, abs(x));
	}

	if (cnt & 1) {
		cout << sum - (mi << 1);
	} else {
		cout << sum;
	}
	return 0;
}
