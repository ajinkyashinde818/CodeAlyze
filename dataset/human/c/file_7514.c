#include<stdio.h>

int main(void) {
	int data[10000];
	int cnt = 0;
	int i;
	
	do {
		scanf("%d", &data[cnt]);
		cnt++;
	} while (data[cnt-1] != 0);
	
	for(i = 0; i < cnt-1; i++) {
		printf("Case %d: %d\n", i+1, data[i]);
	}
	
	return 0;
}
