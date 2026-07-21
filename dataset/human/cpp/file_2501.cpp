#include <iostream>
#include <cstring>
#include <vector>

#include <cmath>

using namespace std;

int main() {
	long long n;
	cin >> n;

	vector<long long> a;
	long long temp_a;
	for (long long  i = 0; i < n; i++) {
		cin >> temp_a;
		a.push_back(temp_a);
	}
	long long mass_minas = 0;
	for (long long i = 0; i < n; i++) {
		if (a.at(i) < 0) {
			mass_minas++;
		}
	}

	vector<long long> a_sub;

	for (long long i = 0; i < n; i++) {
		a_sub.push_back(abs(a.at(i)));
	}

	long long ans = 0;
	if (mass_minas % 2 == 0) {
		for (long long i = 0; i < n; i++) {
			ans = ans + a_sub.at(i);
		}
	}

	else {
		long long min;
		min = abs(a_sub.at(0));
		for (long long i = 0; i < n; i++) {
			if (min > a_sub.at(i)) {
				min = a_sub.at(i);
			}
		}
		for (long long i = 0; i < n; i++) {
			ans = ans + a_sub.at(i);
		}
		ans = ans - min * 2;
	}
	cout << ans;

	return 0;
}
