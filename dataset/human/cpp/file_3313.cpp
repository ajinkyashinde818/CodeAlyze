#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
int main() {
	int n;
	long long sum = 0;
	bool b = false;
	cin >> n;
	long long m = 100000000007;
	long long a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		sum += abs(a);
		if (m > abs(a)) {
			m = abs(a);
		}
		if (a < 0) {
			b = b ^ 1;
		}
	}
	if (b) {
		sum -= m * 2;
	}
	cout << sum << endl;
	return 0;
}
