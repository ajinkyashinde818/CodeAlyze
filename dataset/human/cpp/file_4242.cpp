#include <cstdio>
#include <vector>
#include <map>

const int MN = 100005;

int N, A[MN], B[MN], X, cnt, M, Ans;
std::map<int, int> mp;

int vis[MN];
std::vector<int> G[MN];
void DFS(int u) {
	vis[u] = 1;
	for (int v : G[u]) if (!vis[v]) DFS(v);
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]), ++mp[A[i]], X ^= A[i];
	for (int i = 1; i <= N; ++i) scanf("%d", &B[i]), --mp[B[i]];
	++mp[X];
	for (auto p : mp) if (p.second < 0) return puts("-1"), 0;
	for (auto &p : mp) p.second = ++cnt;
	for (int i = 1; i <= N; ++i) if (A[i] != B[i]) {
		int u = mp[B[i]], v = mp[A[i]];
		G[u].push_back(v);
		G[v].push_back(u);
		++M;
	}
	for (int i = 1; i <= cnt; ++i) if (!G[i].empty())
		if (!vis[i]) ++Ans, DFS(i);
	if (!G[mp[X]].empty()) --Ans;
	printf("%d\n", M + Ans);
	return 0;
}
