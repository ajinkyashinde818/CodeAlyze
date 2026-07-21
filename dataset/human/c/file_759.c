#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N;
	char S[100001];
	scanf("%d", &N);
	scanf("%s", S);

	int i, count[26] = {};
	long long total = 1;
	for (i = 0; S[i] != 0; i++) count[S[i] - 'a']++;
	for (i = 0; i < 26; i++) total = total * (count[i] + 1) % 1000000007;

	printf("%lld\n", (total + 1000000006) % 1000000007);
	fflush(stdout);
	return 0;
}
