#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>

using namespace std;

int N, M;
char a[50][50], b[50][50];

bool match(int x, int y) {
	for (int i = x; i < x + M; i++) {
		for (int j = y; j < y + M; j++) {
			if (b[i - x][j - y] != a[i][j])
				return false;
		}
	}
	return true;
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
	for (int i = 0; i <= N - M; i++) {
		for (int j = 0; j <= N - M; j++) {
			if (match(i, j)) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
