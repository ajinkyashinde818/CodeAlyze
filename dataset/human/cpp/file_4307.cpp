#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <map>
using namespace std;
inline int read()
{
	int f = 1, x = 0;
	char ch;

	do{
		ch = getchar();
		if (ch == '-')
			f = -1;
	}while(ch < '0' || ch > '9');
	do{
		x = x * 10 + ch - '0';
		ch = getchar();
	}while(ch >= '0' && ch <= '9');
	return f * x;
}
const int N = 1e5;

int n, x, cnt;
map<int, int> p;
int a[N + 1], b[N + 1];
struct Edge {
	int to, next;
} edge[(N << 1) + 1];
int start[N + 1], tot;
int vis[N + 1];
int ans;

inline void addedge(int u, int v)
{
	edge[++tot] = Edge{ v, start[u] };
	start[u] = tot;
	edge[++tot] = Edge{ u, start[v] };
	start[v] = tot;
	ans++;
	return;
}
inline void dfs(int u)
{
	vis[u] = 1;
	for (int i = start[u]; i; i = edge[i].next) {
		int v = edge[i].to;
		if (!vis[v])
			dfs(v);
	}
	return;
}
int main()
{
	n = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		p[a[i]]++;
		x ^= a[i];
	}
	p[x]++;
	for (int i = 1; i <= n; i++) {
		b[i] = read();
		p[b[i]]--;
	}
	for (map<int, int>::iterator it = p.begin(); it != p.end(); it++) {
		if ((*it).second < 0) {
			printf("-1\n");
			return 0;
		}
		(*it).second = ++cnt;
	}
	for (int i = 1; i <= n; i++)
		if (a[i] != b[i])
			addedge(p[a[i]], p[b[i]]);

	for (int i = 1; i <= cnt; i++) {
		if (start[i] && !vis[i]) {
			ans++;
			dfs(i);
		}
	}

	if (start[p[x]])
		ans--;
	printf("%d\n", ans);
	return 0;
}
