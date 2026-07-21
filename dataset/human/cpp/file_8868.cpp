#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <stack>
#include <queue>
#include <sstream>
#include <fstream>
#include <float.h>
#include <cmath>
#include <cstring>

using namespace std;
#define int long long

signed main() {
	int N, M;
	char A[52][52] = {}, B[52][52] = {};
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			cin >> B[i][j];
		}
	}
	for (int i = 0; i <= N-M; i++) {
		for (int j = 0; j <= N-M; j++) {
			int tmp = 0;
			for (int k = 0; k < M; k++) {
				for (int l = 0; l < M; l++) {
					if (A[i + k][j + l] == B[k][l]) tmp++;
				}
			}
			if (tmp == M*M) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
