/*
AtCoder Beginner Contest 092 B - Chocolate 結果:
*/

#include<stdio.h>

//#define DEBUG1
//#define DEBUGF

int main() {
	int n,d,x;
	int a[100];
	int ans = 0;
	scanf("%d %d %d", &n, &d, &x);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
#ifdef DEBUG1
	printf("%d\n%d\n%d\n", n, d, x);
	for (int i = 0; i < n; i++) {
		printf("%d", &a[i]);
}
#endif
	for (int i = 0; i < n; i++) {
		ans += 1 + ((d - 1) / a[i]);
	}
	ans += x;
	printf("%d\n", ans);
#ifdef DEBUGF
	getch();
#endif
	return 0;
}
