#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<long long> as;
	long long sum = 0;
	for(int i=0;i<n;++i){
		long long a;
		cin >> a;
		as.push_back(a);
		sum += a;
	}
	long long sum_int = 0;
	long long minval = 1LL<<60;
	for (int i = 0; i < n; ++i) {
		sum_int += as[i];
		if (i + 1 != n) {
			minval = min(minval, abs(sum - 2 * sum_int));
		}
	}
	cout << minval << endl;
}
