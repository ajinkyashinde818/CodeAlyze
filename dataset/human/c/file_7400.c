#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int i = 0,c;
	int x[10000];
	while (1){
		scanf("%d", &x[i]);
		if (x[i] == 0) {
			c = i;
			break;
		}
		i++;
	}
	for (i = 0; i < c; i++) {
		printf("Case %d: %d\n",i+1, x[i]);
	}

}
