#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	int mi = 0;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin>>a[i];
		sum += abs(a[i]);

		if (a[i] < 0) {
			mi++;
		}
	}

	if (mi % 2 == 0) {
		cout << sum << endl;
	} else {
		int mn = 1010101010;
		for (int i = 0; i < n; i++) {
			mn = min(mn, abs(a[i]));
		}
		cout << sum - mn * 2 << endl;
	}

	return 0;
}
