#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 100000;
const int INF = (1<<30);
struct node{
	int pos, key;
	node(int _p=0, int _k=0):pos(_p), key(_k){}
}a[MAXN + 5], b[MAXN + 5];
bool cmp_pos(node a, node b) {
	return a.pos < b.pos;
}
bool cmp_key(node a, node b) {
	return a.key < b.key;
}
int siz[MAXN + 5], fa[MAXN + 5];
int N;long long x;
int Find(int x) {
	if( fa[x] == x ) return x;
	else return fa[x] = Find(fa[x]);
}
void Union(int x, int y) {
	int fx = Find(x), fy = Find(y);
	if( fx != fy ) {
		siz[fy] += siz[fx];
		fa[fx] = fy;
	}
}
int solve1() {
	for(int i=1;i<=N;i++) {
		fa[i] = i;
		siz[i] = 1;
	}
	for(int i=1;i<=N;i++)
		Union(a[i].pos, b[i].pos);
	for(int i=1;i<N;i++)
		if( a[i].key == a[i+1].key ) Union(a[i].pos, a[i+1].pos);
	sort(a+1, a+N+1, cmp_pos); sort(b+1, b+N+1, cmp_pos);
	for(int i=1;i<=N;i++)
		if( a[i].key == b[i].key )
			siz[Find(a[i].pos)]--;
	int ret = 0;
	for(int i=1;i<=N;i++)
		if( fa[i] == i && siz[i] ) ret += (siz[i] + 1);
	return ret;
}
int solve2(int p, int q) {
	sort(a+1, a+N+1, cmp_key);
	int temp = a[p].key; p = a[p].pos;
	sort(a+1, a+N+1, cmp_pos);
	sort(b+1, b+N+1, cmp_pos);
	for(int i=1;i<=N;i++) {
		if( a[i].key == temp && b[i].key != temp) {
			p = i;
			break;
		}
	}
	sort(a+1, a+N+1, cmp_key);
	for(int i=1;i<=N;i++)
		if( a[i].pos == p ) a[i].key = x;
	sort(a+1, a+N+1, cmp_key); sort(b+1, b+N+1, cmp_key);
	for(int i=1;i<=N;i++) {
		fa[i] = i;
		siz[i] = 1;
	}
	for(int i=1;i<=N;i++)
		Union(a[i].pos, b[i].pos);
	for(int i=1;i<N;i++)
		if( a[i].key == a[i+1].key ) Union(a[i].pos, a[i+1].pos);
	sort(a+1, a+N+1, cmp_pos); sort(b+1, b+N+1, cmp_pos);
	int ret = -1;
	for(int i=1;i<=N;i++)
		if( a[i].key == b[i].key )
			siz[Find(a[i].pos)]--;
	if( siz[Find(p)] == 0 )
		ret = 1;
	for(int i=1;i<=N;i++)
		if( fa[i] == i && siz[i] ) ret += (siz[i] + 1);
	return ret;
}
int main() {
	scanf("%d", &N);
	for(int i=1;i<=N;i++) {
		scanf("%d", &a[i].key);
		a[i].pos = i;
		x ^= a[i].key;
	}
	for(int i=1;i<=N;i++) {
		scanf("%d", &b[i].key);
		b[i].pos = i;
	}
	bool f1 = true, f2 = true;
	sort(a+1, a+N+1, cmp_key); sort(b+1, b+N+1, cmp_key);
	for(int i=1;i<=N;i++)
		f1 = f1 && (a[i].key == b[i].key);
	int p = -1, q;
	for(int i=1;i<=N;i++)
		if( b[i].key == x ) p = i;
	if( p == -1 ) f2 = false;
	else {
		bool f3 = true;
		int i = 1, j = 1;
		while( i <= N && j <= N ) {
			if( j == p ) {
				j++;
				continue;
			}
			if( a[i].key != b[j].key ) {
				if( f3 ) {
					q = i;
					f3 = false, i++;
					continue;
				}
				else {
					f2 = false;
					break;
				}
			}
			i++, j++;
		}
		if( f3 ) q = N;
	}
	int ans = INF;
	if( (!f1) && (!f2) ) {
		puts("-1");
		return 0;
	}
	if( f1 ) ans = min(ans, solve1());
	if( f2 ) ans = min(ans, solve2(q, p));
	printf("%d\n", ans);
}
