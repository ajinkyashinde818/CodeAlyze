#include <algorithm>
#include <cmath>
#include <fstream>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>


using namespace std;




int main() {
	int N;
	int cnt = 0;
	long long sum = 0;
	long long absmin = 99999999999;

	cin >> N;
	vector<long long> A(N);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (A[i] < 0)
			cnt++;
		if (abs(A[i]) < absmin)
			absmin = abs(A[i]);
		sum += abs(A[i]);
	}

	if (cnt % 2)
		cout << sum - 2*absmin <<endl;
	else
		cout << sum << endl;

	return 0;
}
