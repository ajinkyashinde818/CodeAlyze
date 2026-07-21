#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;


int main() {
	long long int N, sum[2] = {0,0},min;
	cin >> N;
	vector<long long int> a(N);

	for (int i = 0; i < N;i++) {
		cin >> a[i];
		sum[1] += a[i];
	}
	sum[0] += a[0];
	sum[1] -= a[0];
	min = abs(sum[0] - sum[1]);

	for (int i = 1; i < N-1;i++) {
		sum[0] += a[i];
		sum[1] -= a[i];
		if (abs(sum[0] - sum[1]) < min) {
			min = abs(sum[0] - sum[1]);
		}
		
	}
	cout << min << endl;
	return 0;
}
