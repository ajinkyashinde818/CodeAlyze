#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	long long a[n];
	long long sum[n][2];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sum[0][0] = a[0] + a[1];
	sum[0][1] = -a[0] - a[1];
	for(int i = 1; i < n - 1; i++) {
		sum[i][0] = max(sum[i-1][0], sum[i-1][1]) + a[i+1];
		sum[i][1] = max(sum[i-1][0] - 2*a[i]- a[i+1], sum[i-1][1] + 2*a[i] - a[i+1]);
	}
	cout << max(sum[n-2][0], sum[n-2][1]);
	return 0;
}
