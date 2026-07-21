#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N, ANS = 1, MOD = 1000000007;
	string S;
	cin >> N >> S;
	S = 'W' + S + 'W';
	vector<long long> V1, V2;
	V1.resize(N * 2 + 1);
	V2.resize(N * 2);
	for (int i = 0; i < N * 2 + 1; i++) {
		if (S[i] == S[i + 1]) V1[i] = 0;
		else V1[i] = 1;
	}
	for (int i = 0; i < N * 2; i++) {
		if (V1[i] == 0) {
			V2[i] = 0;
			V1[i + 1] = V1[i + 1] ^ 1;
		}
		else {
			V2[i] = 1;
		}
	}
	long long Cur = 0;
	for (int i = 0; i < N * 2; i++) {
		if (V2[i] == 0) {
			if (Cur == 0) {
				cout << 0 << endl;
				return 0;
			}
			ANS *= Cur;
			ANS %= MOD;
			Cur--;
		}
		else {
			Cur++;
		}
	}
	if (Cur != 0) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i <= N; i++) {
		ANS *= i;
		ANS %= MOD;
	}
	cout << ANS << endl;
}
