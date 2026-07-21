#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	scanf("%d", &N);

	vector<long long> A(N), B(N);

	scanf("%lld", &A[0]);
	B[0] = A[0];
	for (int i = 1; i < N; i++) {
		scanf("%lld", &A[i]);
		B[i] = B[i - 1] + A[i];
	}
	// printf("%lld\n", B[N - 1]);

	long long result = abs(B[N - 1] - B[0] * 2);
	for (int i = 1; i < N - 1; i++) {
		result = min(abs(B[N - 1] - B[i] * 2), result);
		// printf("%d %d\n", A[i], B[i]);
	}
	printf("%lld\n", result);

	return 0;
}
