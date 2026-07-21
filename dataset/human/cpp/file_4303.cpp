#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> gr[N], vec;
int n, rn, cmp, a[N], b[N], cnt[N], x;
bool mark[N];
void compress() {
	sort(vec.begin(), vec.end());
	vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
	if (vec.size() > n + 1) {
		cout << -1;
		exit(0);
	}
	for (int i = 0; i < n; i++)
		a[i] = lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin(), b[i] = lower_bound(vec.begin(), vec.end(), b[i]) - vec.begin();
	x = lower_bound(vec.begin(), vec.end(), x) - vec.begin();
	return;
}
void dfs(int v) {
	mark[v] = 1;
	for (auto u : gr[v])
		if (!mark[u])
			dfs(u);
	return;
}	
int main() {
	ios_base::sync_with_stdio (false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i], x ^= a[i], vec.push_back(a[i]);
	for (int i = 0; i < n; i++)
		cin >> b[i], vec.push_back(b[i]);
	vec.push_back(x);
	compress();
	for (int i = 0; i < n; i++)
		cnt[a[i]]++, cnt[b[i]]--;
	cnt[x]++;
//	cout << "X = " << x << endl;
//	for (int i = 0; i < n; i++) {
//		cout << "I = " << i << " : " << a[i] << ", " << b[i] << endl;
//	}
	for (int i = 0; i <= n; i++) {
		if (cnt[i] < 0) {
			cout << -1;
			return 0;
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i])
			rn++, gr[a[i]].push_back(b[i]), gr[b[i]].push_back(a[i]);
	}
	for (int i = 0; i <= n; i++) {
		if (!mark[i] && (i == x || !gr[i].empty()))
			dfs(i), cmp++;
	}
	cout << rn + cmp - 1;
	return 0;
}
