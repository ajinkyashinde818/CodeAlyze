#include <stdio.h>
#include <algorithm>
using namespace std;
using ll = long long;

ll mod = 1e9 + 7;
int n, cnt[26];
char s[100010];
int main() {
	scanf("%d", &n);
	scanf("%s", s);
	for (int i = 0; i < n; i++)
		cnt[s[i] - 'a']++;
	ll r = 1;
	for (int i = 0; i < 26; i++)
		r = r * (cnt[i] + 1) % mod;
	r = (r + mod - 1) % mod;
	printf("%lld\n", r);
}
