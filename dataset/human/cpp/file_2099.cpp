#include<iostream>
#include<string>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main() {
	int N;
	cin >> N;
	int i;
	vector<long long> minus;
	long long abs_min = 100000000;
	long long ans = 0;
	for (i = 0; i < N; i++) {
		long long a;
		cin >> a;
		abs_min = min(abs_min, abs(a));
		if (a < 0) {
			minus.push_back(a);
			ans -= a;
		}
		else {
			ans += a;
		}
	}
	sort(minus.begin(), minus.end());
	reverse(minus.begin(), minus.end());
	if (minus.size() % 2 == 0) {
		cout << ans;
	}
	else {
		cout << ans - abs_min * 2;
	}
}
