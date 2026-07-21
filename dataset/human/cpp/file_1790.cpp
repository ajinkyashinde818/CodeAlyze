#include <cstdio>
#include <stack>
using namespace std;

int n, m;
stack<int> s;
bool dp[200001] = { false };

int main(){
	int tmp;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &tmp);
		s.push(tmp);
	}
	while (!s.empty()) {
		tmp = s.top(); s.pop();
		if (!dp[tmp]) {
			dp[tmp] = true;
			printf("%d\n", tmp);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!dp[i]) {
			printf("%d\n", i);
		}
	}

	return 0;
}
