#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>
#include<set>
#include<numeric>
#include<functional>
#include<unordered_map>
#include<cmath>
#include<cstdlib>
#include<cassert>
#include<climits>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<string> A(N), B(M);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < M; i++)
		cin >> B[i];

	for (int i = 0; i < N - M + 1; i++) {
		for (int j = 0; j < N - M + 1; j++) {
			bool flag = true;
			for (int k = 0; k < M; k++) {
				for (int l =0; l < M; l++) {
					if (A[i + k][j + l] != B[k][l]) {
						flag = false;
						break;
					}
				}
				if (!flag)
					break;
			}
			if (flag) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
}
