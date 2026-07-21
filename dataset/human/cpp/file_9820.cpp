#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;
int n, cnt[26]; char s[maxn];
inline int inc(int x, int y) {x += y; return x >= mod ? x - mod : x;}
inline int mul(int x, int y) {return (ll)x * y % mod;}
int main()
{
	scanf("%d\n%s", &n, s + 1);
	for (int i = 1; i <= n; i ++)
		++ cnt[s[i] - 'a'];
	int ans = 1;
	for (int c = 0; c < 26; c ++)
		ans = mul(ans, cnt[c] + 1);
	ans = inc(ans, mod - 1);
	printf("%d\n", ans);
	return 0;
}
