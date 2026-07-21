#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <set>
using namespace std;

int main() {
	int n; long long a[200000] = {};
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i >= 1) a[i] += a[i - 1];
	}
	long long s = a[n - 1], m = abs(a[n - 1] - 2*a[0]);
	for (int i = 1; i < n-1; i++) {
		m = min(abs(s - 2*a[i]), m);

	}
	cout << m << endl;
}
