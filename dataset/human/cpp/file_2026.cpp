#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>	

using namespace std;

int main() {
	int n;
	long long sum = 0;
	cin >> n;
	vector<long long> A(n);
	int count = 0;
	for (int i = 0; i < n; ++i) {
		cin >> A[i];
		if (A[i] < 0) {
			++count;
			A[i] = -A[i];
		}
	}
	sort(A.begin(), A.end());

	if (count % 2 == 0) {
		for (int i = 0; i < n; ++i) {
			sum += abs(A[i]);
		}
	}
	else {
		sum = -abs(A[0]);
		for (int i = 1; i < n; ++i) {
			sum += abs(A[i]);
		}
	}

	cout << sum << endl;

	return 0;
}
