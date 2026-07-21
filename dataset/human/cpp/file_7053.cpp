#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int main()
{
	int n;
	scanf("%d", &n);
	vector<ii> a(n, ii());
	vector<int> b(n, 0);
	map<int, int> ma, mb;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i].first);
		a[i].second = i;
		if (ma.count(a[i].first)) ma[a[i].first]++;
		else ma[a[i].first] = 1;
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &b[i]);
		if (mb.count(b[i])) mb[b[i]]++;
		else mb[b[i]] = 1;
	}
	for (auto it = mb.begin(), end = mb.end(); it != end; ++it) {
		if (ma.count(it->first) && ma[it->first]+(it->second) > n) {
			puts("No");
			exit(0);
		}
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int p = 0, c; 1; ++p) {
		while (p < n && a[0].first == b[p]) ++p;
		if (p == n) {
			puts("No");
			break;
		}
		for (c = 0; c < n; ++c) {
			if (a[c].first == b[(p+c)%n]) break;
		}
		if (c == n) {
			puts("Yes");
			vector<int> ans(n, 0);
			for (int i = 0; i < n; ++i) ans[a[i].second] = b[(p+i)%n];
			printf("%d", ans[0]);
			for (int i = 1; i < n; ++i) printf(" %d", ans[i]);
			puts("");
			break;
		}
	}
}
