#include <stdio.h>
char s[500000], d;
int q, x, l, r, t;
int main() {
	scanf(" %s", s + 200000);
	l = 200000;
	r = 200000;
	while (s[r] != NULL)r++;
	r--;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d", &t);
		if (t == 1)x = 1 - x;
		if (t == 2) {
			scanf("%d", &t);
			scanf(" %c", &d);
			if ((t + x) % 2) {
				l--;
				s[l] = d;
			}
			else {
				r++;
				s[r] = d;
			}
		}
	}
	if (x) {
		for (int i = r; i >= l; i--) {
			printf("%c", s[i]);
		}
	}
	else {
		for (int i = l; i <= r; i++) {
			printf("%c", s[i]);
		}
	}
	printf("\n");
}
