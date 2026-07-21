#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	long min;
	int N, minus_count, min_index;
	vector<long> A;

	cin >> N;

	int temp;
	minus_count = 0;
	min = 1000000000;
	min_index = 0;
	for(int i = 0; i < N; i++) {
		cin >> temp;

		if(temp < 0)
			minus_count++;

		if(abs(temp) < min) {
			min = abs(temp);
			min_index = i;
		}

		A.push_back(temp);
	}

	long ans = 0;
	for(int i = 0; i < N; i++) {
		if(i == min_index && minus_count % 2 == 1)
			ans -= min;
		else
			ans += abs(A[i]);
	}
	cout << ans << endl;

	return 0;
}
