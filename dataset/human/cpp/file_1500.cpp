#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

int n, k;
bool ans[100000][1000];

signed main() {
	cin >> n;
	
	for (k = 1; k * (k - 1) < 2 * n; k++);
	if (k * (k - 1) != 2 * n) { cout << "No" << endl; return 0; }
	
	cout << "Yes" << endl;
	int i, j;
	
	int cor = 0;
	for (i = 0; i < k; i++) {
		for (j = i + 1; j < k; j++) {
			ans[cor][i] = true;
			ans[cor][j] = true;
			cor++;
		}
	}
	
	cout << k << endl;
	for (j = 0; j < k; j++) {
		vector<int> s;
		for (i = 0; i < n; i++) {
			if (ans[i][j]) s.push_back(i);
		}
		cout << s.size();
		for (i = 0; i < s.size(); i++) {
			cout << " " << s[i] + 1;
		}
		cout << endl;
	}
	return 0;
}
