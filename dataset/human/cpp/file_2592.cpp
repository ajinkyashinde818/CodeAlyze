#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<long long> A(N);
	for (auto &x : A) {
		cin >> x;
	}

	long long abs_sum = 0;
	long long abs_min = 1LL << 40;
	int neg = 0;
	for (auto x : A) {
		abs_sum += abs(x);
		abs_min = min(abs_min, abs(x));
		if (x < 0) {
			++neg;
		}
	}

	if (neg % 2 == 0) {
		cout << abs_sum << endl;
	}
	else {
		cout << abs_sum - 2 * abs_min << endl;
	}
}
