// ABC054B - 

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

int main() {
	int N, M;
	cin >> N >> M;

	string A[N];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	string B[M];
	for (int i = 0; i < M; i++) {
		cin >> B[i];
	}

	for (int i = 0; i < N - M + 1; i++) {
		for (int j = 0; j < N - M + 1; j++) {
			bool temp = true;
			for (int k = 0; k < M; k++){
				if (A[k + i].substr(j, M) != B[k]) {
					temp = false;
					break;
				}
			}
			if (temp == true) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}

	cout << "No" << endl;

	return 0;
}
