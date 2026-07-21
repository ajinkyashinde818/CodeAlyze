#include <iostream>
#include <fstream>
#include <string> 
#include <cmath>  
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <functional>
using namespace std;
using ll = long long;

int main() {
	int N,M;
	cin >> N >> M;
	vector<string> A(N), B(M);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> B[i];
	}
	for (int i = 0; i < N - M + 1; i++) {
		for (int j = 0; j < N - M + 1; j++) {
			int c = 0;
			for (int k = i; k < M + i; k++) {
				for (int l = j; l < M + j; l++) {
					if (A[k][l] != B[k - i][l - j])break;
					c++;
					if (c == M*M) {
						cout << "Yes" << endl;
						return 0;
					}
				}
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
