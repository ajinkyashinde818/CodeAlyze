#include<math.h>
#include<map>
#include<iostream>
#include <algorithm>
#include <string>
#include<vector>
#include<array>
#include<tuple>
#include<queue>
#include<stack>
#include<iomanip>
#include<bitset>
#include <list>
#include<numeric>
//AtCoderC++.cpp

using namespace std;

inline int ceiling(int n, int d) {
	return n % d == 0 ? n / d : n / d + 1;
}


int N, M;
bool match(int offset, vector<char>& A, vector<char>& B) {
	for (size_t i = 0; i < M; i++) {
		for (size_t j = 0; j < M; j++) {
			if (A[i*N + j + offset] != B[i*M + j])return false;
		}
	}
	return true;
}

int main() {
	cin >> N >> M;
	auto A = vector<char>(N*N);
	for (size_t i = 0; i < A.size(); i++) cin >> A[i];
	auto B = vector<char>(M*M);
	for (size_t i = 0; i < B.size(); i++) cin >> B[i];
	for (size_t i = 0; i <= N - M; i++) {
		for (size_t j = 0; j <= N - M; j++) {
			if (match(i*N + j, A, B)) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
}
