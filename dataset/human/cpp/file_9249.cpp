#include<iostream>
#include<map>
#include<cmath>
#include<string>

using namespace std;

void debug(char a[100][100], string s, int N) {
	cout << "debug:" << s << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << i << "," << j << ":=" << a[i][j] << endl;
		}
	}
}

int main() {
	int N, M;
	char a[100][100];
	char b[100][100];


	cin >> N;
	cin >> M;

	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < M; i++) {
		cin >> b[i];
	}

	//debug(a, "a", N);
	//debug(b, "b", M);

	char c[100][100];
	for (int i = 0; i < N-M+1; i++) {
		for (int j = 0; j < N-M+1; j++) {
			if (a[i][j] == b[0][0]) {
				for (int k = 0; k < M; k++) {
					for (int l = 0; l < M; l++) {
						c[k][l] = a[k+i][l+j];
					}
				}
				//debug(c, "c", M);
				int flag = 1;
				for (int x = 0; x < M; x++) {
					for (int y = 0; y < M; y++) {
						if (c[x][y] != b[x][y]) flag = 0;
					}
				}
				if (flag) {
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
	}

	cout << "No" << endl;

	return 0;
}
