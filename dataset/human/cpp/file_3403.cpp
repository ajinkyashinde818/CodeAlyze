#include <bits/stdc++.h>
using namespace std;
long long N;
long long A[100001];
long long ans = 0;


int main () {
	cin >> N;
	for (long long n = 0; n < N; n ++) {
		cin >> A[n];
	}
	sort(A, A + N, [](long long i, long long j)->bool {return abs(i) < abs(j);});
	reverse(A, A + N);
	for (long long n = 0; n < N - 1; n ++) {
		if (A[n] < 0) {
			A[n] *= -1;
			A[n + 1] *= -1;
		}
	}
	for (long long n = 0; n < N; n ++) {
		ans += A[n];
	}
	cout << ans << endl;
}
