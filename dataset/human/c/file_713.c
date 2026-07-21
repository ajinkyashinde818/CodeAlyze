#include <stdio.h>

#define MOD 1000000007
int n;
char s[110000];
int table[30];
int main(){
	unsigned long long ans = 1;
	scanf("%d%s", &n, s);
	for(int i = 0; i < n; ++i) ++table[s[i] - 'a'];
	for(int i = 0; i < 26; ++i) ans = ans * (table[i] + 1) % MOD;
	printf("%llu\n", ans - 1);
}
