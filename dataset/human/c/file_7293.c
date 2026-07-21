#include <stdio.h>
int h, w, k, g, f, t, d, e;
char s[400][400];
int x[400][400];
int main() {
	scanf("%d%d%d", &h, &w, &k);
	for (int i = 0; i < h; i++) {
		scanf(" %s", s[i]);
	}
	for (int i = 0; i < h; i++) {
		g = 1;
		for (int j = 0; j < w; j++) {
			if (s[i][j] == '#') {
				g = 0;
			}
		}
		if (g == 0) {
			d = i;
			break;
		}
	}
	for (int i = d; i < h; i++) {
		g = 1;
		e = 0;
		for (int j = 0; j < w; j++) {
			if (s[i][j] == '#') {
				g = 0;
				e++;
			}
		}
		if (g) {
			for (int j = 0; j < w; j++) {
				x[i][j] = x[i - 1][j];
			}
		}
		else {
			for (int j = 0; j < w; j++) {
				if (e && (j == 0 || s[i][j - 1] == '#')) {
					t++;
					x[i][j] = t;
					e--;
				}
				else x[i][j] = x[i][j - 1];
			}
		}
	}
	for (int i = d - 1; i >= 0; i--) {
		for (int j = 0; j < w; j++) {
			x[i][j] = x[i + 1][j];
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w - 1; j++) {
			printf("%d ", x[i][j]);
		}
		printf("%d\n", x[i][w - 1]);
	}
}
