#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

const int MAXN = 100005;

int N;
int a[MAXN], b[MAXN];
map <int, int> cnt;
map <int, int> dad, rnk;
set <int> S;
int sol;

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
	for (int i = 0; i < N; i++)
		scanf("%d", b + i);
}

int find(int x) {
	return dad[x] == x ? x : dad[x] = find(dad[x]);
}

void join(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	if (rnk[x] > rnk[y])
		swap(x, y);
	dad[x] = y;
	rnk[y] += rnk[x] == rnk[y];
	sol--;
}

int solve() {
	for (int i = 0; i < N; i++) {
		a[N] ^= a[i];
		b[N] ^= b[i];
	}
	
	for (int i = 0; i <= N; i++) {
		dad[a[i]] = a[i];
		dad[b[i]] = b[i];
		if (a[i] != b[i] || i == N) {
			S.insert(a[i]);
			S.insert(b[i]);
		}
	}
	
	if (S.empty())
		return 0;
	
	for (int i = 0; i <= N; i++) {
		cnt[a[i]]++;
		cnt[b[i]]--;
	}
	
	for (auto it : cnt)
		if (it.second)
			return -1;
	
	sol += (int)S.size() - 1;
	for (int i = 0; i < N; i++)
		if (a[i] != b[i]) {
			join(a[i], b[i]);
			sol++;
		}
		
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}
