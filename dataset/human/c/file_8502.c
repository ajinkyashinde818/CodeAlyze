#include <stdio.h>

int puzzle(int height) {
	int cell[10][5] = {0,0};
	int score = 0;
	int i, j, k;
	int row;
	int fall[5] = { 0 };
	int no_change;

	for (i = 0; i < height; i++) {
		row = height - i - 1;
		scanf("%d%d%d%d%d", &cell[row][0], &cell[row][1], &cell[row][2], &cell[row][3], &cell[row][4]);
	}
	do {
		no_change = height;
		for(i=0;i<height;i++){
			k = 2;
			row = height - i - 1;
			for (j = 0; j < 3; j++)
				if ((cell[row][j] == cell[row][j + 1]) && (cell[row][j + 1] == cell[row][j + 2])&&(cell[row][2]!=0)) {
					fall[j] = 1;
					fall[j + 1] = 1;
					fall[j + 2] = 1;
					k += 1;
				}
			if (k != 2)
				score += cell[row][2] * k;
			else
				no_change--;
			if (fall[2] == 1) {
				for (k = row; k < height; k++) {
					if (k == height - 1) {
						for (j = 0; j < 5; j++)
							if (fall[j] == 1) {
								cell[k][j] = 0;
								fall[j] = 0;
							}
					}
					else
						for (j = 0; j < 5; j++)
							if (fall[j] == 1)
								cell[k][j] = cell[k + 1][j];
				}
			}
		}
	} while (no_change != 0);
	return score;
}

int main(void) {
	int height;

	while (1) {
		scanf("%d", &height);
		if (height == 0)
			break;
		printf("%d\n",puzzle(height));
	}
	return 0;
}
