#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	long long A, X[100000] = {}, count = 0, Minus = 0, Zero = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A;
		X[i] = abs(A);
		if (A < 0) Minus++;
		else if (A == 0) Zero = 1;
		count += X[i];
	}
	if (Minus % 2 == 0 || Zero == 1) {
		cout << count;
	}
	else {
		sort(X, X + N);
		cout << count - X[0] * 2;
	}
}
