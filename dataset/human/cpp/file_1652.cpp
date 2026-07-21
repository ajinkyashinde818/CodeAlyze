#include <bits/stdc++.h>

using namespace std;

int n, at;
vector<vector<int>> ans;

int main() {
	scanf("%d", &n);
	for (int i = 0; ; i++) {
		ans.emplace_back();
		for (int j = 0; j < i; j++) {
			at++;
			ans[i].push_back(at);
			ans[j].push_back(at);
			if (at > n)
				break;
		}
		if (at == n) {
			puts("Yes");
			printf("%d\n", (int)ans.size());
			for (auto& j : ans) {
				printf("%d", (int)j.size());
				for (int k : j)
					printf(" %d", k);
				puts("");
			}
			return 0;
		} else if (at > n) {
			printf("No\n");
			return 0;
		}
	}
	return 0;
}
