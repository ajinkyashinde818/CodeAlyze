#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int>A(N);
	int count = 0;
	for (int n = 0; n < N; ++n) {
		int num;
		cin >> num;
		if (num < 0 ) {
			A[n] = -num;
			count++;
		}
		else {
			A[n] = num;
		}
	}	
	long long ans = 0;
	for (int n = 0; n < N; ++n) {
		ans += A[n];
	}
	sort(A.begin(), A.end());
	if (1 == count %2) {
		ans -= 2*A[0];
	}
	cout << ans << endl;
	return 0;
}
