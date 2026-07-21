#include <iostream>
#include <string>
using namespace std;

int main() {
	int N, M;
	string A[50], B[50];
	cin >> N >> M;
	bool check = false;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> B[i];
	}

	for (int i = 0; i <= N - M; i++) { //上
		for (int j = 0; j <= N - M; j++) { //左
			bool check2 = true;
			for (int k = 0; k < M; k++) {
				if (A[i + k].substr(j, M) != B[k]) check2 = false;
			}
			if (check2) check = true;
		}
	}

	if (check) cout << "Yes" << endl;
	else cout << "No" << endl;
}
