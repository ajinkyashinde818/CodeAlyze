#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200010;
int N;
int A[MAX_N], B[MAX_N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < N; i++)
		cin >> B[i];
	
	reverse(B, B + N);
	
	int e = -1, a, b, x, y;
	
	for (int i = 0; i < N; i++) {
		if (A[i] == B[i]) {
			e = A[i];
			a = i;
			break;
		}
	}
	
	if (e == -1) {
		cout << "Yes\n";
		for (int i = 0; i < N; i++)
			cout << B[i] << " ";
		cout << "\n";
		return 0;
	}
	
	for (int i = N - 1; i >= 0; i--) {
		if (A[i] == B[i]) {
			b = i;
			break;
		}
	}
	
	for (int i = 0; i < N; i++) {
		if (A[i] == e || B[i] == e) {
			x = i;
			break;
		}
	}
	
	for (int i = N - 1; i >= 0; i--) {
		if (A[i] == e || B[i] == e) {
			y = i;
			break;
		}
	}
	
	int k = a, i = 0, j = N - 1;
	while (k <= b) {
		if (i < x) {
			swap(B[i], B[k]);
			++i;
			++k;
			continue;
		}
		if (j > y) {
			swap(B[j], B[k]);
			--j;
			++k;
			continue;
		}
		break;
	}
	
	if (k <= b) cout << "No\n";
	else {
		cout << "Yes\n";
		for (int i = 0; i < N; i++)
			cout << B[i] << " ";
		cout << "\n";
	}
	
	return 0;
}
