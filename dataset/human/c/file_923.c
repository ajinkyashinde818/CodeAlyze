// AOJ 2331: A Way to Invite Friends
// 2017.10.4 bal4u@uu
// 2017.11.22

#include <stdio.h>
#include <stdlib.h>

#define MAX 100001
int tbl[MAX];

char buf[20], *p;
int getint()
{
	int n = 0;
	while (*p >= '0') n = (n<<3) + (n<<1) + (*p++ & 0xf);
	return n;
}

int main()
{
	int n, a, b, i, sum, ans;

	fgets(p=buf, 10, stdin), n = getint();
	for (i = 0; i < n; i++)	{
		fgets(p=buf, 20, stdin);
		a = getint()-1, p++, b = getint()-1;
		tbl[a]++, tbl[b+1]--;
	}
	sum = ans = 0;
	for (i = 0; i <= MAX; i++) {
		sum += tbl[i];
		if (sum >= i) ans = i;
	}
	printf("%d\n", ans);
	return 0;
}
