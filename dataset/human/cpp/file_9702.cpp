#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

char s[100010];
int vis[26];

int main(){
	int n; scanf("%d", &n);
	scanf("%s", s);
	int l = 0, r = 0;
	for (int i = 0; i < n; i++){
		vis[s[i] - 'a']++;
	}
	long long ans = 1;
	for (int i = 0; i < 26; i++){
		ans = ans * (vis[i] + 1) % mod;
	}
	printf("%lld\n", (ans - 1 + mod) % mod);
	return 0;
}
