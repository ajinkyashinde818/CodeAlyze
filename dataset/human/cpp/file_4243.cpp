//  Created by Sengxian on 2017/6/18.
//  Copyright (c) 2017年 Sengxian. All rights reserved.
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
inline int readInt() {
	int n = 0, ch = getchar();
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) n = n * 10 + ch - '0', ch = getchar();
	return n;
}

const int MAX_N = 100000 + 3;
int n, a[MAX_N], b[MAX_N], sortedA[MAX_N], sortedB[MAX_N];
bool same[MAX_N];
vector<int> vs, pos[MAX_N];

int main() {
	n = readInt();
	int x = 0, y = 0;
	for (int i = 1; i <= n; ++i) x ^= sortedA[i] = a[i] = readInt();
	for (int i = 1; i <= n; ++i) y ^= sortedB[i] = b[i] = readInt();
	sortedA[0] = a[0] = x, sortedB[0] = b[0] = y;
	sort(sortedA, sortedA + n + 1);
	sort(sortedB, sortedB + n + 1);
	
	int idx = -1;
	for (int i = 0; i <= n; ++i)
		if (sortedA[i] != sortedB[i])
			return puts("-1"), 0;
	
	int m = unique(sortedA, sortedA + n + 1) - sortedA;
	for (int i = 1; i < n + 1; ++i) same[i] = a[i] == b[i];
	for (int i = 0; i < n + 1; ++i) a[i] = lower_bound(sortedA, sortedA + m, a[i]) - sortedA;
	for (int i = 0; i < n + 1; ++i) if (!same[i]) pos[a[i]].push_back(i);
	for (int i = 0; i < n + 1; ++i) b[i] = lower_bound(sortedA, sortedA + m, b[i]) - sortedA;
	
//	for (int i = 0; i < n + 1; ++i) cout << a[i] << ' '; cout << endl;
//	for (int i = 0; i < n + 1; ++i) cout << b[i] << ' '; cout << endl;
	
	static bool vis[MAX_N];
	int ans = 0;
	for (int i = 0; i < n + 1; ++i) if (!same[i] && !vis[i]) {
		static int q[MAX_N];
		int l = 0, r = 0;
		vis[i] = true, q[r++] = i;
		while (r - l >= 1) {
			int u = q[l++];
			for (int i = 0; i < (int)pos[b[u]].size(); ++i) {
				int v = pos[b[u]][i];
				if (!vis[v]) vis[v] = true, q[r++] = v;
			}
		}
		if (i == 0) ans += r - 1;
		else ans += r + 1;
	}
	
	printf("%d\n", ans);
			
	return 0;
}
