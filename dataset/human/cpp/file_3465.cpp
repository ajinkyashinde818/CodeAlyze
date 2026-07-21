#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<sstream>
#include<iomanip>
#include<limits>
#include<deque>
#include<map>
#include<list>
#include<set>
#include <unordered_set>
#include<vector>
#include<cmath>
#include<cstdio>
#include<memory>
#include<bitset>
#include<stack>
#include <functional>
#include <queue>
#include <regex>

using namespace std;

constexpr int MOD = 1000000007;
constexpr int INF = 1050000000;


int main() {
	int n; cin >> n;
	int a[100000];
	int mainasu = 0;
	int checkl = 0;
	int checkr = 0;

	int m = INF;

	bool check = false;

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 0) {
			check = true;
		}
		else {
			m = min(m, abs(a[i]));
		}
		if (a[i] < 0) {
			mainasu++;
		}
		
	}

	if (check) {
		for (int i = 0; i < n; i++) {
			ans += abs(a[i]);
		}
	}
	else {
		if (mainasu % 2 == 0) {
			for (int i = 0; i < n; i++) {
				ans += abs(a[i]);
			}
		}
		else {
			for (int i = 0; i < n; i++) {
				ans += abs(a[i]);
			}
			ans -= 2*m;
		}
	}

	cout << ans << endl;







}
