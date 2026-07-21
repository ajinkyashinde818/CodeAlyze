#include<stdio.h>
int main() {
	int i, x[10000];

	for (i = 0; i < 10000; i++) {
		scanf("%d", &x[i]);
		if (!x[i]) break;
	}
	for (i = 0; i < 10000 && x[i]; i++) {
		printf("Case %d: %d\n", i+1, x[i]);
	}
	return 0;
}
