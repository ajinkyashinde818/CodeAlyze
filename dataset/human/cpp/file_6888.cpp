#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int>A(N);
	vector<int>B(N);
	vector<int>C(N + 1);
	vector<int>D(N + 1);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		C[A[i]]++;
	}
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
		D[B[i]]++;
	}
	for (int i = 1; i <= N; ++i) {
		if (C[i] + D[i] > N) {
			cout << "No" << endl;
			return 0;
		}
	}
	for (int i = 1; i <= N; i++) {
		C[i] += C[i - 1];
		D[i] += D[i - 1];
	}
	int x = -1;
	for (int i = 1; i <= N; ++i) {
		x = max(x, C[i] - D[i - 1]);
	}
	cout << "Yes" << endl;
	for (int i = 0; i < N; ++i) {
		if (0 != i) {
			cout << " ";
		}
		cout << B[(i + N - x)%N];
	}
	cout << endl;
	return 0;
}
