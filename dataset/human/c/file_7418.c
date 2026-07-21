#include<stdio.h>
int main(void){
	int x[10001];
	int i;
	int t;

	for (i = 1; i <= 10000;i++) {
		
		scanf("%d",&x[i]);
		
		if (x[i]==0) {
			break;
		}
	}
	for (t = 1; t <= 10000; t++) {
		if (t == i)break;
		printf("Case %d: %d\n", t, x[t]);
	}
	return 0;
	}
