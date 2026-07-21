#include<stdio.h>
int main() {
	int i,x[10000],c=0;
	for (i = 0; i < 10000; i++) {
		scanf("%d", &x[i]);
		if (x[i] == 0)break;
		c++;
	}
	for (i = 0; i < c; i++) {
		printf("Case %d: %d\n",i+1,x[i]);
	}
	return 0;
}
