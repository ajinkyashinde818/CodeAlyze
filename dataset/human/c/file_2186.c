#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void) {
	int i, q, r, t, f, start = 200000, len = 0;
	char c, s[500000];

	scanf("%s", &s[start]);
	scanf("%d", &q);
	len = strlen(&s[start]);
	for (i = 0; i < q; i++) {
		scanf("%d", &t);
		if (t == 1) {
			r++;
			r %= 2;
		}
		else {
			scanf("%d %c", &f, &c);
			if (r == 1) {
				if (f == 1) {
					f = 2;
				}
				else {
					f = 1;
				}
			}
			if (f == 1) {
				s[start - 1] = c;
				start--;
			}
			else {
				s[start + len] = c;
				s[start + len + 1] = '\0';
			}
			len++;
		}
	}
		if (r == 0) {
			printf("%s", &s[start]);
		}
		else {
			for (i = start + len - 1; i >= start; i--) {
				printf("%c", s[i]);
			}
		}

	



	return 0;
}
