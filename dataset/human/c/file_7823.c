#include<stdio.h>
int main(void) {
	int N, K, P;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &K, &P);
		if (K > P) {
			if (K%P != 0)printf("%d\n", K%P);
			else printf("%d\n", K/(K / P));
		}
		else {
			printf("%d\n", K);
		}
	}
	return 0;
}
