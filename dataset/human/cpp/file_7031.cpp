#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>

using namespace std;

const int maxn = 2e5;

int n, a[maxn + 5], b[maxn + 5];
int l[maxn + 5], r[maxn + 5];
int ans[maxn + 5];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i)scanf("%d", &b[i]);
	for (int i = 1; i <= n; ++i)r[a[i]] = i;
	for (int i = n; i > 0; --i)l[b[i]] = i;
	int res = 0;
	for (int i = 1; i <= n; ++i)if (l[i] && r[i])res = max(res, r[i] - l[i] + 1);
	for (int i = 1; i <= n; ++i) {
		int npos = i + res;
		if (npos > n)npos -= n;
		ans[npos] = b[i];
	}
	for (int i = 1; i <= n; ++i) {
		if (a[i] == ans[i]) {
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	for (int i = 1; i <= n; ++i)printf("%d%c", ans[i], " \n"[i == n]);
	return 0;
}
