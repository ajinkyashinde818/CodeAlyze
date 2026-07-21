#include<stdio.h>
int main() {
	int i,n,k,p;
	scanf("%d",&n);
	for (i = 1; i <= n; i++) {
		scanf("%d %d", &k, &p);
		if (k%p == 0) {
			printf("%d\n", p);
		}
		else {
			printf("%d\n", k%p);
		}
	}
	return 0;
}
