#include<stdio.h>
int main() {
	int i, j;
	int x[10000];

	
	for (i = 0;; i++) {
			scanf("%d", &x[i]);
			if (x[i] == 0)
				break;
	}
	for (j = 0;i>0; j++,i--) {
		printf("Case %d: %d\n", j + 1, x[j]);
	}

	return 0;
}
