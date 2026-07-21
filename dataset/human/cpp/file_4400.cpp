#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int a[MAXN], b[MAXN], n;
int dx[MAXN*2], dx_top = 0;
int T[MAXN*2];
stack<int> stk[MAXN*2];
queue<int> que;

int vis[MAXN*2], fa[MAXN*2];
inline int findf(int nd)
{ return fa[nd]?fa[nd]=findf(fa[nd]):nd; }

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	int cur = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dx[++dx_top] = a[i];
		cur ^= a[i];
	}
	dx[++dx_top] = cur;
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		dx[++dx_top] = b[i];
	}
	sort(dx+1, dx+dx_top+1);
	dx_top = unique(dx+1, dx+dx_top+1)-dx-1;
	cur = lower_bound(dx+1, dx+dx_top+1, cur)-dx;
	T[cur]++;
	for (int i = 1; i <= n; i++) {
		a[i] = lower_bound(dx+1, dx+dx_top+1, a[i])-dx;
		b[i] = lower_bound(dx+1, dx+dx_top+1, b[i])-dx;
		T[b[i]]--;
		T[a[i]]++;
	}
	int cnt = 0, now, cc = 0;
	for (int i = 1; i <= dx_top; i++) {
		if (T[i] != 0 && T[i] != 1) {
			cout << -1 << endl;
			return 0;
		}
		cnt += T[i];
		if (T[i]) now = i;
	}
	if (cnt > 1) {
		cout << -1 << endl;
		return 0;
	}
	int B = 0;
	vis[cur] = 1;
	B++;
	for (int i = 1; i <= n; i++) {
		if (a[i] != b[i]) {
			cc++;
			if (!vis[a[i]]) vis[a[i]] = 1, B++;
			if (!vis[b[i]]) vis[b[i]] = 1, B++;
			int u = findf(a[i]), v = findf(b[i]);
			if (u != v) fa[u] = v, B--;
		}
	}
	if (cc) 
		cout << cc+B-1 << endl;
	else cout << 0 << endl;
	return 0;
}
