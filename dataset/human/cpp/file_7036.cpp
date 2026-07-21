#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
//using namespace atcoder;

int main() {
	int N;
	cin >> N;
	vector<int> A(N), B(N);
	map<int, int> ANum, BNum;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		ANum[A[i]]++;
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
		BNum[B[i]]++;
	}
	for (int i = 0; i <= N; i++) {
		if (ANum.find(i) == ANum.end() || BNum.find(i) == BNum.end()) continue;
		if (ANum[i] + BNum[i] > N) {
			cout << "No" << endl;
			return 0;
		}
	}
	reverse(B.begin(), B.end());
	int j = N - 1;
	for (int i = 0; i < N; i++) {
		if (A[i] == B[i]) {
			while (A[i] == B[j] || B[i] == A[j]) {
				j--;
				if (j < 0) j = N - 1;
			}
			swap(B[i], B[j]);
		}
	}
	cout << "Yes" << endl;
	for (int b : B) cout << b << " ";
	cout << endl;
}
