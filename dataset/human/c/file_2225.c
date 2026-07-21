#include <stdio.h>
#include <string.h>

int spos, mpos;
char sentou[333333];
char matubi[333333];

int main(void) {
	int i, Q;
	int hanten = 0;
	if (scanf("%114513s", matubi) != 1) return 1;
	mpos = (int)strlen(matubi);
	if (scanf("%d", &Q) != 1) return 1;
	for (i = 0; i < Q; i++) {
		int T, F;
		char C[4];
		if (scanf("%d", &T) != 1) return 1;
		if (T == 1) {
			hanten = !hanten;
		} else if (T == 2) {
			if (scanf("%d%3s", &F, C) != 2) return 1;
			if (F == (hanten ? 2 : 1)) {
				sentou[spos++] = C[0];
			} else {
				matubi[mpos++] = C[0];
			}
		}
	}
	if (hanten) {
		for (i = mpos - 1; i >= 0; i--) {
			putchar((unsigned char)matubi[i]);
		}
		puts(sentou);
	} else {
		for (i = spos - 1; i >= 0; i--) {
			putchar((unsigned char)sentou[i]);
		}
		puts(matubi);
	}
	return 0;
}
