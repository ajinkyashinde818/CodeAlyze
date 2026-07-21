#include<iostream>
using namespace std;
bool check(int, int);
int N, M;
char paper1[51][51], paper2[51][51];
int main() {
	cin >> N >> M;
	for (int y = 1; y <= N; ++y) {
		for (int x = 1; x <= N; ++x) {
			cin >> paper1[x][y];
		}
	}
	for (int y = 1; y <= M; ++y) {
		for (int x = 1; x <= M; ++x) {
			cin >> paper2[x][y];
		}
	}
	int slide = N - M + 1;
	for (int x = 1; x <= slide; ++x) {
		for (int y = 1; y <= slide; ++y) {
			if (check(x, y)) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}

bool check(int x, int y) {
	for (int nx = 0; nx < M; ++nx) {
		for (int ny = 0; ny < M; ++ny) {
			if (paper2[nx + 1][ny + 1] != paper1[nx + x][ny + y]) {
				return false;
			}
		}
	}
	return true;
}
