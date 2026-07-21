#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include<stdio.h>
int main() {
	int x[10000],i,cnt=0;
	for (i = 0; i < 10000; ++i) {
		scanf("%d", &x[i]);
		if (x[i] == 0) break;
		cnt++;
	}
	for (i = 0; i < cnt; ++i) printf("Case %d: %d\n", i+1, x[i]);
	return 0;
}
