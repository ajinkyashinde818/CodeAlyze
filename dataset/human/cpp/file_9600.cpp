#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

int main() {
	int i, j, k, t, N, M;
	char A[51][51], B[51][51];

	cin >> N >> M;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}

	for (i = 0; i < M; i++) {
		for (j = 0; j < M; j++) {
			cin >> B[i][j];
		}
	}

	int flag;
	//cout << endl;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			//cout<< A[i][j];
			flag = 0;
			for (k = 0; k < M; k++) {
				if (k > 49) {
					flag = 1;
					break;
				}
				for (t = 0; t < M; t++) {
					//cout << B[k][t];
					if (t > 49) {
						flag = 1;
						break;
					}
					if (B[k][t] != A[i+k][j+t]) {
						flag = 1;
						break;
					}
				}
				if (flag == 1) break;
				//cout << endl;
			}
			if (flag == 0) {
				cout << "Yes" << endl;
				
				return 0;
			}
		}
		//cout << endl;
	}

	cout << "No" << endl;


	/*
	for (i = 0; i < M; i++) {
		for (j = 0; j < M; j++) {
			cout<< B[i][j];
		}
		cout << endl;
	}
	*/








	return 0;
}
