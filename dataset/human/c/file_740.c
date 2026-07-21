#include <stdio.h>

int main(int argc, char *argv[])
{
	int n;
	char s[100001];
	int count[26];
	int i;
	long long ans;
	
	scanf("%d", &n);
	scanf("%s", s);

	for (i = 0; i < 26; i++) {
		count[i] = 1;
	}
	
	for (i = 0; i < n; i++) {
		count[s[i] - 'a']++;
	}
	
	ans = 1;
	for (i = 0; i < 26; i++) {
		ans *= count[i];
		ans %= 1000000007;
	}
	ans--;
	
	printf("%lld\n", ans);
	
	return 0;
}
