#include <stdio.h>
#include <algorithm>
int n, k, s;
int main() {
	scanf("%d%d%d", &n, &k, &s);
	if (s != 1000000000) {
		for (int i = 0; i < n; i++) {
			if (i < k)printf("%d", s);
			else printf("%d", s + 1);
			if (i < n - 1)printf(" ");
			else printf("\n");
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			if (i < k)printf("%d", s);
			else printf("1");
			if (i < n - 1)printf(" ");
			else printf("\n");
		}
	}
}
