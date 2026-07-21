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
	int n, m;
	cin >> n >> m;
	string s[50] = {}, t[50] = {};
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> t[i];
	}
	bool f = 0;
	for (int i = 0; i <= n - m; i++) {
		for (int j = 0; j <= n - m;j++) {
			bool g = 1;
			for (int k = j; k <= j + m - 1;k++) {
				if (t[k-j] != s[k].substr(i, m)) {
					g = 0;
					break;
				}
			}
			if (g) {
				f = 1;
				break;
			}
		}
	}
	if (f) cout << "Yes" << endl;
	else cout << "No" << endl;
}
