#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#include <climits>
#include <memory>
#include <sstream>
#include <iomanip>
#include <cstdio>

using namespace std;

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	int numM = 0;
	long long sum = 0;
	int min = INT_MAX;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		sum += abs(a);
		if (a < 0) {
			numM++;
		}
		min = std::min(min, abs(a));
	}
	if (numM % 2 == 0) {
		cout << sum << endl;
	}
	else {
		cout << sum - 2 * min << endl;
	}

	return 0;
}
