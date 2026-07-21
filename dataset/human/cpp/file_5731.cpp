#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int lc[MAXN], rc[MAXN], top = 0, root = 0;
int sg[MAXN];

int N;
long long L;
char str[MAXN];

void push(int &nd, const char *str)
{
	if (!nd) nd = ++top;
	if (*str == '\0') return; 
	push(*str == '0' ? lc[nd] : rc[nd], str+1);
}

long long cnt = 0;
inline long long lowbit(long long i)
{ return i&(-i); }

void dfs(int nd, long long dep)
{
	if (!nd) return;
	dfs(lc[nd], dep-1), dfs(rc[nd], dep-1);
	if ((!lc[nd] || !rc[nd]) && lc[nd]+rc[nd]) {
	        cnt ^= lowbit(dep);
	}
}

int main()
{
	scanf("%d%lld", &N, &L);
	for (int i = 1; i <= N; i++) {
		scanf("%s", str);
		push(root, str);
	}
	dfs(root, L);
	if (cnt != 0) cout << "Alice" << endl;
	else cout << "Bob" << endl;
	return 0;
}
