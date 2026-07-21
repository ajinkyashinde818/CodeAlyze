#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <iomanip>
#include <bitset>
using namespace std;

typedef long long ll;


int cnt[100005];

int main() {
	int n; cin >> n;
	int t = 0, sum = 0;
	while (sum < n) {
		t++;
		sum += t;
	}
	if (sum != n) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	cout << t + 1 << endl;
	
	vector<vector<int>> ans(t + 1, vector<int>(t));
	for (int i = 1; i <= t; i++) ans[0][i - 1] = i, cnt[i]++;
	for (int i = 1; i < t + 1; i++) {
		for (int j = 0; j < i; j++) {
			for (int b : ans[j]) {
				if (cnt[b] >= 2) continue;
				cnt[b]++;
				ans[i][j] = b;
				break;
			}
		}
		int idx = i;
		for (int j = ans[i][i - 1] + 1; j <= n; j++) {
			if (idx >= t) break;
			if (cnt[j] >= 1) continue;
			
			cnt[j]++;
			ans[i][idx] = j;
			idx++;
		}
	}
	for (int i = 0; i < t + 1; i++) {
		cout << ans[i].size() << " ";
		for (int j = 0; j < t; j++) cout << ans[i][j] << (j < t - 1 ? " " : "\n");
	}
	return 0;
}
