#include <stdio.h>

int main(void)
{
	char s[50][50];
	int h, w, i, j, f = 0;
	scanf("%d%d", &h, &w);
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			scanf("%c", &s[i][j]);
			while (s[i][j] == 10) scanf("%c", &s[i][j]);
		}
	}
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			if (s[i][j] == 35) {
				if (i == 0 && j == 0) {
					s[0][1] == 46 && s[1][0] == 46 ? f = 1 : 0;
				}
				else if (i == 0 && j == w - 1) {
					s[0][w - 2] == 46 && s[1][w - 1] == 46 ? f = 1 : 0;
				}
				else if (i == h - 1 && j == 0) {
					s[h - 2][0] == 46 && s[h - 1][1] == 46 ? f = 1 : 0;
				}
				else if (i == h - 1 && j == w - 1) {
					s[w - 2][h - 1] == 46 && s[h - 2][w - 1] == 46 ? f = 1 : 0;
				}
				else if (i == 0) {
					s[i][j - 1] == 46 && s[i][j + 1] == 46 && s[i + 1][j] == 46 ? f = 1 : 0;
				}
				else if (i == h - 1) {
					s[i][j - 1] == 46 && s[i][j + 1] == 46 && s[i - 1][j] == 46 ? f = 1 : 0;
				}
				else if (j == 0) {
					s[i - 1][j] == 46 && s[i + 1][j] == 46 && s[i][j + 1] == 46 ? f = 1 : 0;
				}
				else if (j == w - 1) {
					s[i - 1][j] == 46 && s[i + 1][j] == 46 && s[i][j - 1] == 46 ? f = 1 : 0;
				}
				else {
					s[i + 1][j] == 46 && s[i - 1][j] == 46 && s[i][j + 1] == 46 && s[i][j - 1] == 46 ? f = 1 : 0;
				}
			}
		}
	}
	printf("%s", f ? "No" : "Yes");
	return 0;
}
