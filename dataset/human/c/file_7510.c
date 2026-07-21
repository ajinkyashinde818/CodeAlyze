#include<stdio.h>
int main(void) {
	int a[9999], i;
	i = 0;
	while (1) {
		i = i + 1;
		scanf("%d", &a[i]);
		if (a[i] == 0) {
			break;
		}
	}
	i = 0;
	while (1) {
		i=i +1;
		if (a[i] == 0) {
			break;
		}
		printf("Case %d: %d\n", i, a[i]);
	}
	return 0;
}
