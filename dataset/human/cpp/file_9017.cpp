#include <iostream>
#include <vector>
#include <string> 

using namespace std;

bool check(vector<string> &A, vector<string> &B, int px, int py) {
	for (int y = 0; y < B.size(); y++) {
		for (int x = 0; x < B.size(); x++) {
			if (A[y + py][x + px] != B[y][x]) return false;
		}
	}
	return true;
}

int main(int argc, char *argv[]) {
	int N, M;
	cin >> N >> M;

	vector<string> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	vector<string> B(M);
	for (int i = 0; i < M; i++) cin >> B[i];

	for (int py = 0; py <= N - M; py++) {
		for (int px = 0; px <= N - M; px++) {
			if (check(A, B, px, py)) {
				printf("Yes\n");
				return 0;
			}
		}
	}

	printf("No\n");
	return 0;
}
