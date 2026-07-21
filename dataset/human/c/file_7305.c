#include <stdio.h>

int main()
{
	int i, j, H, W, K;
	char s[302][302] = {};
	scanf("%d %d %d", &H, &W, &K);
	for (i = 1; i <= H; i++) scanf("%s", &(s[i][1]));

	int k = 1, l, m, id[302][302] = {}, flag;
	for (i = 1; i <= H; i++) {
		flag = 0;
		for (j = 1; j <= W; j++) {
			id[i][j] = -1;
			if (flag == 1) {
				if (s[i][j] == '#') k++;
				for (l = i; id[l][j] == -1; l--) id[l][j] = k;
			} else if (s[i][j] == '#') {
				flag = 1;
				for (m = 1; m <= j; m++) {
					for (l = i; id[l][m] == -1; l--) id[l][m] = k;
				}
			}
		}
		if (flag == 1) k++;
	}
	
	for (i = H; id[i][1] == -1; i--);
	for (j = 1; j <= W; j++) {
		for (l = i + 1; l <= H; l++) id[l][j] = id[i][j];
	}
		
	for (i = 1; i <= H; i++) {
		for (j = 1; j <= W; j++) printf("%d ", id[i][j]);
		printf("\n");
	}
	fflush(stdout);
	return 0;
}
