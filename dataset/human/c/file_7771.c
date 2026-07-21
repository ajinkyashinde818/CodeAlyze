#include <stdio.h>
int main(void) {
	int n, i, k, p, x;
	scanf("%d",&n);
	for (i = 1; i <= n; i++) {
		scanf("%d %d",&k,&p);
		x = k % p;
		if(x != 0)
			printf("%d\n",x);
		else
			printf("%d\n",p);
	}
	return 0;
}
