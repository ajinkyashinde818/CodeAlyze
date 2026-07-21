#include <stdio.h>
char s[1000005];
int y[1000005];
int x[1000005][12];
int d, t;
int main() {
	scanf(" %s", s);
	while (s[d] != NULL)d++;
	for (int i = 0; i < d; i++) {
		y[d - 1 - i] = s[i] - '0';
	}
	for (int i = 0; i < d; i++) {
		if (y[i] > 5) {
			y[i] -= 10;
			y[i + 1]++;
		}
	}
	for (int i = 0; i <= d + 1; i++) {
		for (int j = 0; j < 12; j++) {
			x[i][j] = 100000000;
		}
	}
	x[0][y[0] + 5] = 0;
	for (int i = 0; i <= d; i++) {
		for (int j = 0; j < 12; j++) {
			if (j < 5) {
				t = 5 - j + x[i][j];
				if (x[i + 1][y[i + 1] + 5] > t)x[i + 1][y[i + 1] + 5] = t;
			}
			if (5 <= j && j < 11) {
				t = j - 5 + x[i][j];
				if (x[i + 1][y[i + 1] + 5] > t)x[i + 1][y[i + 1] + 5] = t;
			}
			if (j == 0) {
				t = 5 + x[i][j];
				if (x[i + 1][y[i + 1] + 4] > t)x[i + 1][y[i + 1] + 4] = t;
			}
			if (j == 10) {
				t = 5 + x[i][j];
				if (x[i + 1][y[i + 1] + 6] > t)x[i + 1][y[i + 1] + 6] = t;
			}
			if (j == 11) {
				t = 4 + x[i][j];
				if (x[i + 1][y[i + 1] + 6] > t)x[i + 1][y[i + 1] + 6] = t;
			}
		}
	}
	printf("%d\n", x[d + 1][5]);
}
