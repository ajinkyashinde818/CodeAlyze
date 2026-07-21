#include <cstring>
#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;
const int MAXN = 100010;

int n, a[MAXN], b[MAXN];

void input() {
	scanf( "%d", &n );
	a[0] = b[0] = 0;
	for( int i = 1; i <= n; ++i ) {
		scanf( "%d", a+i );
		a[0] ^= a[i];
	}
	for( int i = 1; i <= n; ++i ) {
		scanf( "%d", b+i );
		b[0] ^= b[i];
	}
}

int ta[MAXN], tb[MAXN];
bool check() {
	for( int i = 0; i <= n; ++i )
		ta[i] = a[i], tb[i] = b[i];
	sort( ta, ta+n+1 );
	sort( tb, tb+n+1 );
	for( int i = 0; i <= n; ++i )
		if( ta[i] != tb[i] ) return false;
	for( int i = 0; i <= n; ++i ) {
		a[i] = lower_bound( ta, ta+n+1, a[i] ) - ta;
		b[i] = lower_bound( tb, tb+n+1, b[i] ) - tb;
	}
	return true;
}

namespace Graph {
	int head[MAXN], nxt[MAXN<<1], to[MAXN<<1], eidx = 0;
	void init() {
		memset( head, -1, sizeof(head) );
	}
	void adde( int u, int v ) {
		to[eidx] = v, nxt[eidx] = head[u], head[u] = eidx++;
		to[eidx] = u, nxt[eidx] = head[v], head[v] = eidx++;
	}
}

bool exist[MAXN] = {0}, vis[MAXN] = {0};
void dfs( int u ) {
	using namespace Graph;
	vis[u] = 1;
	for( int i = head[u]; ~i; i = nxt[i] ) {
		int v = to[i];
		if( vis[v] ) continue;
		dfs(v);
	}
}
void solve() {
	Graph::init();
	int ans = 0;
	for( int i = 0; i <= n; ++i ) {
		if( !i || a[i] != b[i] ) {
			exist[a[i]] = exist[b[i]] = 1;
			if( a[i] != b[i] && i ) {
				Graph::adde( b[i], a[i] );
				++ans;
			}
		}
	}
	for( int i = 0; i <= n; ++i )
		if( exist[i] && !vis[i] )
			dfs(i), ++ans;
	printf( "%d\n", ans-1 );
}

int main() {
	input();
	if( !check() ) {
		puts("-1");
		return 0;
	}
	solve();
	return 0;
}
