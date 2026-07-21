#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int i,a;
	int array[10000];

	

	for ( i = 0; ( i < 10000); i++){
		scanf("%d", &array[i]);
		if (array[i] == 0) {
			break;
		}
	}
	for (i = 0; (i < 10000); i++) {
		if (array[i] == 0) {
			break;
		}
		printf("Case %d: %d\n", i+1, array[i]);
	}
	return 0;
}
