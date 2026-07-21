#include<bits/stdc++.h>

using namespace std;

int main() {
	cin.sync_with_stdio(false);
	
	int N, M;
	cin >> N >> M;
	char A[50][50],B[50][50];
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 0;i < M;i++) {
		for (int j = 0;j < M;j++) {
			cin >> B[i][j];
		}
	}
	int flag;
	for (int i = 0;i <= N - M;i++) {
		for (int j = 0;j <= N - M;j++) {
			flag = true;
			for (int k = 0;k < M;k++) {
				for (int l = 0;l < M;l++) {
					if (A[i + k][j + l] != B[k][l]) {
						flag = false;
						break;
					}
				}
				if (!flag) {
					break;
				}
			}
			if (flag) {
				cout << "Yes" << endl;
				break;
			}
		}
		if (flag) {
			break;
		}
	}
	if (!flag) {
		cout << "No" << endl;
	}
	return 0;
}
