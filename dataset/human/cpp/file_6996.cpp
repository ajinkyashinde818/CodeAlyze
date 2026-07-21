#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

long long bp(long long a, int n) {
	if(n == 0) return 1;
	if(n & 1) return a * bp(a % mod, n - 1) % mod;
	return bp(a * a % mod, n / 2) % mod;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int a[n], b[n], cnt[n + 1] = {0};
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	for(int i = 0; i < n; i++) {
		cin >> b[i];
		cnt[b[i]]++;
	}
	for(int i = 1; i <= n; i++) {
		if(cnt[i] > n) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	reverse(b, b + n);
	for(int i = 0; i < n; i++) {
		if(a[i] == b[i]) {
			for(int j = 0; j < n; j++) {
				if(b[j] != a[i] and a[j] != b[i]) {
					swap(b[i], b[j]);
					break;
				}
			}
		}
	}
	for(int i = 0; i < n; i++) cout << b[i] << ' ';
	return 0;
}
