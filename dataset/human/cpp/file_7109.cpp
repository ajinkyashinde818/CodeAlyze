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

	long long n, i, j, k, ans;
	cin >> n;
	vector<long long> a(n), s(n);
	for (i = 0; i < n; i++) {
		cin >> a[i];
		if (i == 0) s[i] = a[i];
		else s[i] = s[i - 1] + a[i];
	}
	ans = 1LL << 61;
	for (i = 0; i < n - 1; i++) {
		ans = min(ans, abs(s[i] - (s[n - 1] - s[i])));
	}
	cout << ans << "\n";

	return 0;
}
