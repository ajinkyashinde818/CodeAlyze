#include <cstdio>
#include <vector>
#include <map>
#include <set>

using namespace std;

const int MAXN = 1e5+5;

int n, a[MAXN], b[MAXN];
vector <int> G[MAXN];
int sol;

map <int,int> ind;
multiset <int> s;
int cnt;

int sz;
bool bio[MAXN];

int dfs(int x) {
	sz++;
	bio[x] = 1;
	int ret = 1;
	for (int i: G[x]) {
		if (bio[i]) continue;
		ret &= dfs(i);
	}

	return ret & (x != a[n]);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a+i);
		if (ind[a[i]] == 0) ind[a[i]] = ++cnt;
		a[n] ^= a[i];
		a[i] = ind[a[i]];
		s.insert(a[i]);
	}
	if (ind[a[n]] == 0) ind[a[n]] = ++cnt;
	a[n] = ind[a[n]];
	s.insert(a[n]);
	for (int i = 0; i < n; ++i) {
		scanf("%d", b+i);
		if (ind[b[i]] == 0) ind[b[i]] = ++cnt;
		b[n] ^= b[i];
		b[i] = ind[b[i]];
		if (s.find(b[i]) == s.end()) sol = -1;
		else s.erase(s.find(b[i]));
	}
	if (ind[b[n]] == 0) ind[b[n]] = ++cnt;
	b[n] = ind[b[n]];
	if (s.find(b[n]) == s.end()) sol = -1;
/*
	for (int i = 0; i <= n; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");
	for (int i = 0; i <= n; ++i) {
		printf("%d ", b[i]);
	}
	printf("\n");
*/
	if (sol == -1) {
		printf("-1\n");
		return 0;
	}


	for (int i = 0; i <= n; ++i) {
		if (a[i] != b[i]) {
			G[a[i]].push_back(b[i]);
			G[b[i]].push_back(a[i]);
			sol++;
		}
	}

	for (int i = 1; i <= cnt; ++i) {
		if (bio[i]) continue;
		sz = 0;
		bool t = dfs(i);
		if (sz > 1) sol += t;
	}
	if (a[n] != b[n]) sol--;

	printf("%d\n", sol);
	return 0;
}
