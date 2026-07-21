#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n, i, j, k, x, best = 0, s;

	cin >> n;
	vector<long long> a(n), b(n);
	s = 0;
	for (i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = - a[i] - a[i];
		s += a[i];
	}

	sort(b.rbegin(), b.rend());
	for (i = 1; i < n; i++) b[i] += b[i - 1];

	best = s;
	for (i = 2; i <= n; i += 2) best = max(best, s + b[i - 1]);

	cout << best << "\n";


	return 0;
}
