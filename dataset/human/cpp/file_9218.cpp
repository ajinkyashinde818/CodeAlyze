#include<string>
#include<iostream>

using namespace std;

int main(void) {
	int N, M;
	cin >> N >> M;
	char A[50][50], B[50][50];
	bool exist = false;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> B[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i + M - 1 >= N || j + M - 1 >= N) {

			}else {
				bool match = true;
				for (int y = 0; y < M; y++) {
					for (int x = 0; x < M; x++) {
						if (A[i + y][j + x] != B[y][x]) match = false;
					}
				}
				if (match == true) {
					exist = true;
				}
			}
		}
	}

	if (exist==true) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}
