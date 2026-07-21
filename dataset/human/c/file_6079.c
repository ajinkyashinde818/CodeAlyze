#include <stdio.h>
int main(void) {
	int i, n, minr, nowr, maxd, nowd;
	scanf("%d", &n); /*n >= 2*/
	scanf("%d %d", &minr, &nowr);
	maxd = nowd = nowr - minr;
	for (i = 3; i <= n; i++) {
		if (nowr < minr) minr = nowr;
		scanf("%d", &nowr);
		nowd = nowr - minr;
		if (nowd > maxd) maxd = nowd;
	}
	printf("%d\n", maxd);
	return 0;
}
