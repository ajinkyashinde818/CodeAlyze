#include <bits/stdc++.h>
using namespace std;

vector<int> g[100055];

int main() {
	int n;
	cin >> n;
	
	int k = 1;
	
	while (k * (k - 1) / 2 < n) k++;
	
	if (k * (k - 1) / 2 != n) {
		puts("No");
		return 0;
	}
	
	printf("Yes\n%d\n", k);
	
	int cnt = 0;
	
	for (int i = 0; i < k; i++) for (int j = i + 1; j < k; j++) {
		g[i].push_back(cnt);
		g[j].push_back(cnt++);
	}
	
	for (int i = 0; i < k; i++) {
		printf("%d", (int)g[i].size());
		
		for (auto u : g[i]) printf(" %d", u + 1);
		puts("");
	}
}
