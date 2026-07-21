#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, X = 0;
	cin >> N;
	for (int i = 1; i <= 500; i++) {
		if (i * (i + 1) / 2 == N) {
			X = i;
			break;
		}
	}
	if (X == 0) cout << "No";
	else {
		cout << "Yes" << endl << X + 1 << endl;
		for (int i = 0; i < X; i++) {
			cout << X;
			for (int j = 1; j <= i; j++) {
				cout << " " << i * (i + 1) / 2 + j;
			}
			for (int j = i; j < X; j++) {
				cout << " " << j * (j + 1) / 2 + i + 1;
			}
			cout << endl;
		}
		cout << X;
		for (int i = 1; i <= X; i++) {
			cout << " " << i * (i + 1) / 2;
		}
	}
}
