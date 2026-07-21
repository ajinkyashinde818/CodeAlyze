#include <bits/stdc++.h>
using namespace std;

int N, M;
string A[50],B[50];

bool search(int h, int w) {
	bool match = true;

	for (int i = 1; i < M; i++) {
		if (B[i] != A[h + i].substr(w, M)) {
			match = false;
			break;
		}
	}
	return match;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < M; i++) cin >> B[i];

	bool ans = false;
	for (int i = 0; i < N - M + 1; i++) {
		for (int j = 0; j < N - M + 1; j++) {
			if (B[0] == A[i].substr(j, M)) {
				ans = search(i, j);
			}
			if (ans) break;
		}
		if (ans) break;
	}

	if (ans) cout << "Yes" << endl;
	else cout << "No" << endl;
}
