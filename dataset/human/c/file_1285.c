#include <stdio.h>
#define NUM (8)

int VALUE[NUM] = {
	12121414, 21214141, 12141412, 21414121,
	14141212, 41412121, 14121214, 41212141
};
int RIDE[NUM][NUM] = {
	{1, 2, 1, 2, 1, 4, 1, 4}, {2, 1, 2, 1, 4, 1, 4, 1},
	{1, 2, 1, 4, 1, 4, 1, 2}, {2, 1, 4, 1, 4, 1, 2, 1},
	{1, 4, 1, 4, 1, 2, 1, 2}, {4, 1, 4, 1, 2, 1, 2, 1},
	{1, 4, 1, 2, 1, 2, 1, 4}, {4, 1, 2, 1, 2, 1, 4, 1}
};

int main(void) {
	int gast[NUM], remain, value, index, i, r, k, diff;

	while (scanf(
			"%d %d %d %d %d %d %d %d ", gast, gast+1, gast+2,
			gast+3, gast+4, gast+5, gast+6, gast+7) != EOF) {
		for (remain = i = 0; i < NUM; i++) {
			remain += gast[i];
		}
		value = 41412121;
		for (i = 0; i < NUM; i++) {
			for (r = k = 0; k < NUM; k++) {
				diff = gast[k] - RIDE[i][k];
				if (diff > 0) {
					r += diff;
				}
			}
			if (remain > r || (remain == r && value > VALUE[i])) {
				remain = r;
				index = i;
				value = VALUE[i];
			}
		}
		for (i = 0; i < (NUM-1); i++) {
			printf("%d ", RIDE[index][i]);
		}
		printf("%d\n", RIDE[index][i]);
	}
	return 0;
}
