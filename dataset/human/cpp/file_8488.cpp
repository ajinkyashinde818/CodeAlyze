#include<iostream>
using namespace std;

int N, M;
char a[60][60], b[60][60];

bool judge(int sy, int sx) {
	bool f = true;
	for (int i = sy; i < sy + M; i++) {
		for (int j = sx; j < sx + M; j++) {
			if (a[i][j] != b[i - sy][j - sx])f = false;
		}
	}
	return f;
}


int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			cin >> b[i][j];
		}
	}
	for (int sy = 0; sy <= N - M; sy++) {
		for (int sx = 0; sx <= N - M; sx++) {
			if (judge(sy, sx)) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
