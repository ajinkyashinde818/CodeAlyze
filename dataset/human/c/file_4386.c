#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void*a,const void *b) {
	return *(int*)a - *(int*)b;
}

int main() {
	const int ok = 1000;
	int n, x, y, cnt = 0;
	/*scanf("%d%d", &n, &t);
	for (int i = 0; i < n; i++) {
		int s;
		scanf("%d", &s);
		N[s] = ok;
	}
	for (int i = 0; i < t; i++) {
		int s;
		scanf("%d", &s);
		T[s] = ok;
	}

	for (int i = 0; i < 110; i++) if (N[i] == T[i] && N[i] == ok)printf("%d\n", i);*/
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &x, &y);
		if (x == y) {
			cnt++;
			if (cnt == 3) {
				printf("Yes");
				return 0;
			}
		}
		else cnt = 0;
	}
	printf("No");
	return 0;
}
