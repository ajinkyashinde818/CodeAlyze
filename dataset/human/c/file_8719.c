#include<stdio.h>

int main(void) {
	int N;
	scanf("%d",&N);
	
	int a[N];
	int i;
	for (i = 0; i < N; i++) {
		scanf("%d",&a[i]);
	}
	
	int b = a[0];
	for(i = 1; i <= N; i++) {
		if(b == 2) {
			printf("%d",i);
			break;
		}
		b = a[b-1];
		if(i == N && b != 2) {
			printf("-1");
		}
	}
	
	printf("\n");
	return 0;
}
