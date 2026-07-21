#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <string>
#include <map>
#include <set>
using namespace std;

int main()
{
	int32_t N, M;
	cin >> N >> M;

	vector<string> A(N);
	for (int32_t i = 0; i < N; i++) {
		cin >> A[i];
	}

	vector<string> B(M);
	for (int32_t i = 0; i < M; i++) {
		cin >> B[i];
	}

	for (int32_t row = 0; row <= N - M; row++) {
		for (int32_t col = 0; col <= N - M; col++) {
			bool matched = true;
			for (int32_t row_m = 0; row_m < M; row_m++) {
				for (int32_t col_m = 0; col_m < M; col_m++) {
					if (A[row + row_m][col + col_m] != B[row_m][col_m]) {
						matched = false;
						break;
					}
				}
			}
			if (matched) {
				cout << "Yes"  << endl;
				return 0;
			}
		}
	}

	cout << "No"  << endl;

	return 0;
}
