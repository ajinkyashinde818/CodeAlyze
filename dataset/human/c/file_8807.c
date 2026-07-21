#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>
#include <string.h>

char mark[50][50];

int main(void) {
	uint32_t h, w;
	bool isolatedCellsExist = false;

	scanf("%"PRIu32" %"PRIu32"\n", &h, &w);

	for (uint32_t row = 0; row < h; row++) {
		for (uint32_t col = 0; col < w; col++) {
			scanf("%c", &(mark[row][col]));
		}
		if (row != h - 1) {
			scanf("\n");
		}
	}

	for (uint32_t row = 0; row < h; row++) {
		for (uint32_t col = 0; col < w; col++) {
			if (mark[row][col] == '#') {
				bool isCellIsolated = true;

				if (row != 0) {
					if (mark[row - 1][col] == '#') {
						isCellIsolated = false;
					}
				}
				if (col != 0) {
					if (mark[row][col - 1] == '#') {
						isCellIsolated = false;
					}
				}
				if (row != h - 1) {
					if (mark[row + 1][col] == '#') {
						isCellIsolated = false;
					}
				}
				if (col != w - 1) {
					if (mark[row][col + 1] == '#') {
						isCellIsolated = false;
					}
				}

				if (isCellIsolated) {
					isolatedCellsExist = true;
				}
			}
		}
	}

	printf("%s", isolatedCellsExist ? "No" : "Yes");

	return 0;
}
