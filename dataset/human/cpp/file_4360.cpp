#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;

const int MAXN = 2e5 + 10;
int N;
int A[MAXN], B[MAXN];
int fa[MAXN], tot;
map<int, int> mp;
int ans;

inline int gf(int x) {return x == fa[x] ? x : fa[x] = gf(fa[x]);}

int main() {
	register int i;
	scanf("%d", &N);
	for(i = 1; i <= N; ++i) scanf("%d", A + i), A[0] ^= A[i];
	for(i = 1; i <= N; ++i) scanf("%d", B + i), B[0] ^= B[i];
	for(i = 1; i <= N; ++i) fa[i] = i;
	for(i = 0; i <= N; ++i)
		if(A[i] != B[i] || i == 0) {
			++ans;
			if(!mp[A[i]]) mp[A[i]] = ++tot;
			if(!mp[B[i]]) mp[B[i]] = ++tot;
			fa[gf(mp[A[i]])] = gf(mp[B[i]]);
		}
	--ans;
	for(i = 1; i <= tot; ++i) if(fa[i] == i) ++ans;
	sort(A, A + N + 1); sort(B, B + N + 1);
	for(i = 0; i <= N; ++i) if(A[i] != B[i]) return puts("-1"), 0;
	printf("%d\n", ans - 1);
	return 0;
}
