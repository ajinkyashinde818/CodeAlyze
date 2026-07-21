#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

using ll = long long;

int main() {

	int n;

	cin >> n;

	int minusCount = 0;
	ll minValue = LLONG_MAX;

	ll sum = 0;

	for (int i = 0; i < n; ++i) {
		ll a;
		cin >> a;

		if (a < 0)
			minusCount++;

		minValue = min(minValue, abs(a));
		sum += abs(a);
	}

	if (minusCount % 2 == 1)
		sum -= minValue * 2;

	cout << sum << endl;

	return 0;

}
