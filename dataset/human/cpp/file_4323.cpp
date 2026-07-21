#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <cstring>
#include <numeric>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F0(i,n) for (int i = 0; i < n; i++)
#define F1(i,n) for (int i = 1; i <= n; i++)
#define CL(a,x) memset(x, a, sizeof(x));
#define SZ(x) ((int)x.size())
const double eps = 1e-10;
const int inf = 1000000009;
int i, j, k, m, n, l;
int ans;
int a[100005], b[100005];
set<int> V;
map<int, vector<int> > M;

void dfs(int i) {
	V.insert(i);
	for (int j : M[i]) {
		if (!V.count(j)) dfs(j);
	}
}

int main() {
	//freopen("x.in", "r", stdin);

	cin >> n;
	int x = 0;
	F0(i, n) {
		cin >> a[i];
		x ^= a[i];
	}
	F0(i, n) {
		cin >> b[i];
		if (a[i] != b[i]) {
			M[a[i]].push_back(b[i]);
			M[b[i]].push_back(a[i]);
			ans++;
		}
	}

	multiset<int> S;
	S.insert(x);
	F0(i, n) S.insert(a[i]);

	F0(i, n) if (!S.count(b[i])) {
		cout << -1 << endl;
		exit(0);
	}
	else {
		S.erase(S.find(b[i]));
	}

	F0(i, n) if (a[i] != b[i] && !V.count(a[i])) {
		ans++;
		dfs(a[i]);
	}

	if (M.count(x)) ans--;
	cout << ans << endl;

	return 0;
}
