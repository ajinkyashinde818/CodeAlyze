#include <cstdio>
#include <cmath>

#include <iostream>

#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <deque>

#include <algorithm>

using namespace std;

int g(int a, int b) {
	// cout << a << " " << b << " ";
	while (a % b != 0 && b % a != 0) {
		if (b > a)
			b = b % a;
		else
			a = a % b;
	}
	// cout << min(a, b) << endl;
	return min(a, b);
}

int main() {
	int n;
	cin >> n;
	vector<int> v;
	int flag = 0;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		if (t < 0)
			flag = 1 - flag;
		if (t < 0)
			t = -t;
		v.push_back(t);
	}

	sort(v.begin(), v.end());
	long long int res = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0 && flag == 1)
			res -=v[i];
		else
			res += v[i];
	}	
	cout << res << endl;
}
