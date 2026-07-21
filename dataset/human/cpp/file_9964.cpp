#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const long long mod = 1e9 + 7;

char s[N];
int cnt[26];

int main(){
	int n;
	long long ans;
	scanf("%d",&n);
	scanf("%s", s + 1);
	memset(cnt, 0, sizeof(cnt));
	ans = 1;
	for (int i = 1; i <= n; i++) cnt[s[i] - 'a']++;
	for (int i = 0; i < 26; i++){
		ans *= cnt[i] + 1;
		ans %= mod;
	}
	ans = (ans - 1 + mod) % mod;
	printf("%lld\n", ans);
	return 0;
}
