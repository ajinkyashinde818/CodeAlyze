#include <bits/stdc++.h>

void open() {
	freopen("duliu.in", "r", stdin);
	freopen("duliu.out", "w", stdout);
}

const int MAXN = 100000 + 5;

int N, A[MAXN], B[MAXN];
std::map<int, int> Cnt, M;
std::set<int> S;

int num, Fa[MAXN];

int findFa(int x) {
	return Fa[x] == x ? x : Fa[x] = findFa(Fa[x]);
}

void merge(int x, int y) {
	x = findFa(x), y = findFa(y);
	if (x == y) {
		return ;
	}
	Fa[y] = x;
	--num;
}

int main() {
	// open();
	scanf("%d", &N);
	int x = 0;
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &A[i]);
		Cnt[A[i]]++;
		x ^= A[i];
	}
	Cnt[x]++;
	S.insert(x);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &B[i]);
		if (--Cnt[B[i]] < 0) {
			puts("-1");
			return 0;
		}
		if (A[i] != B[i]) {
			S.insert(A[i]);
			S.insert(B[i]);
		}
	}
	int cnt = 0;
	for (std::set<int>::iterator p = S.begin(); p != S.end(); ++p) {
		M[*p] = ++cnt;	
	}
	int ans = 0;
	for (int i = 1; i <= N; ++i) {
		if (A[i] != B[i]) {
			if (!Fa[M[A[i]]]) {
				Fa[M[A[i]]] = M[A[i]];
				++num;
			}
			if (!Fa[M[B[i]]]) {
				Fa[M[B[i]]] = M[B[i]];
				++num;
			}
		}
	}
	if(!Fa[M[x]]) {
		Fa[M[x]] = M[x];
		++num;
	}
	for (int i = 1; i <= N; ++i) {
		if (A[i] != B[i]) {
			merge(M[A[i]], M[B[i]]);
			++ans;
		}
	}
	ans += num;
	printf("%d\n", ans - 1);
	return 0;
}
