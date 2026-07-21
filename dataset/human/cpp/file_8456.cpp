#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool matches(int N, int M, const vector<string> &A, const vector<string> &B, int i, int j)
{
	for (int s = 0; s < M; ++s) {
		for (int t = 0; t < M; ++t) {
			if (A[i + s][j + t] != B[s][t]) {
				return false;
			}
		}
	}
	return true;
}

bool matches(int N, int M, const vector<string> &A, const vector<string> &B)
{
	for (int i = 0; i <= N - M; ++i) {
		for (int j = 0; j <= N - M; ++j) {
			if (matches(N, M, A, B, i, j)) {
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int N, M;
	cin >> N >> M;
	vector<string> A(N), B(M);
	
	for (auto &A_i : A) cin >> A_i;
	for (auto &B_i : B) cin >> B_i;

	if (matches(N, M, A, B)) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}
