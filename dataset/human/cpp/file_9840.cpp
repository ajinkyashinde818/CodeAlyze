#include <bits/stdc++.h>

using namespace std;

int n, cnt[27];
string s;

int main() {
	scanf("%d", &n);
	cin >> s;
	for (int i = 0; i < n; i++) {
		cnt[s[i] - 'a']++;
	}
	
	int ans = 1;
	for (int i = 0; i < 27; i++)
		ans = (ans * 1ll * (cnt[i]+1)) % 1000000007;
	printf("%d\n", (ans-1+1000000007) % 1000000007);
	
	return 0;
}
