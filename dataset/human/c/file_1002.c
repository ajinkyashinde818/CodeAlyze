// AOJ 2508: King's Inspection
// 2017.10.5 bal4u@uu

#include <stdio.h>

int k[102];
char lst[102], *p;
int c2d[128];
char d2c[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
char ans[102], *q;

int main()
{
	int n, i, j;

	for (i = 0; i < 26; i++) c2d['a'+i] = i;
	for (j = 0; j < 26; j++) c2d['A'+j] = i++;

	while (scanf("%d", &n) && n > 0) {
		for (i = 0; i < n; i++) scanf("%d", k+i);
		scanf("%s", lst);
		i = 0; p = lst, q = ans;
		while (*p) {
			 j = c2d[*p++] - k[i];
			 while (j < 0) j += 52;
			 *q++ = d2c[j];
			 if (++i == n) i = 0;
		}
		*q = 0;
		puts(ans);
	}
	return 0;
}
