#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>

int main(void) {
	int h, w, k;
	char cake[301][301] = { 0 };
	int left, temp, bery_cnt = 0;
	int cake_cut[301][301] = { 0 };

	scanf("%d %d %d", &h, &w, &k);
	for (int i = 0; i < h; i++) scanf("%s", cake[i]);

	for (int i = 0; i < h; i++) {
		left = 0, temp = 0;
		for (int j = 0; j <= w; j++) {
			if (cake[i][j] == '#'){
				temp++;
				if (temp >= 2) {
					bery_cnt++;
					for (int k = left; k < j; k++) cake_cut[i][k] = bery_cnt;
					left = j;
				}
			}
			else if (temp >= 1 && j == w ) {
				bery_cnt++;
				for (int k = left; k < j; k++) cake_cut[i][k] = bery_cnt;
			}
		}
	}

	for (int i = 0; i < h; i++) {
		if (cake_cut[i][0]==0) {
			if (i == 0) {
				for (int j = 1; j < h; j++) {
					if (cake_cut[j][0] != 0) {
						temp = j;
						break;
					}
				}
				for (int k = 0; k < w; k++)cake_cut[0][k] = cake_cut[temp][k];
			}
			else {
				for (int k = 0; k < w; k++)cake_cut[i][k] = cake_cut[i - 1][k];
			}
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) printf("%d ", cake_cut[i][j]);
		printf("\n");
	}
	return 0;
}
