#include <stdio.h>

int main() {
	int N,i,D1,count=0,D2,MAX=0;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d %d", &D1, &D2);
		if (D1 == D2) {
			count = count + 1;
			if (MAX < count) {
				MAX = count;
			}
		}
		else {
			count = 0;
		}
	}
	if (MAX >= 3) {
		printf("Yes");
	}
	else {
		printf("No");
	}
	return 0;
}
