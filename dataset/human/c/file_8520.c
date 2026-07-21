#include<stdio.h>
#include<stdlib.h>

int main() {

	int N;
	int pInput[30];
	int** p;
	int pRowIndex;
	int i;
	int j;
	int k;
	int l;
	int pat;
	int pMovingType[5];
	int t[5];
	int curRow;
	int kai[30] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 4, 4, 4, 6, 6, 6, 5, 5, 5, 3, 3, 3, 3, 3, 3, 3, 3, 3 };

	p = (int**)malloc(sizeof(int*) * 65536);
	for (i = 0; i < 65536; i++) p[i] = (int*)malloc(sizeof(int) * 30);

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		for (j = 0; j < 30; j++) scanf("%d", &pInput[j]);
		for(j = 0; j < 30; j++) if(pInput[j] != kai[j]) break;
		if(j == 30){
			printf("0\n");
			goto next;
		}
		for (j = 0; j < 65536; j++) for (k = 0; k < 30; k++) p[j][k] = pInput[k];
		pRowIndex = 65536;
		pat = 1;
		for (j = 1; j <= 8; j++) {
			for (k = 1; k <= pat * 4; k++) {
				for (l = 1; l <= pRowIndex / 4; l++) {
					if (k % 4 == 1) {
						pMovingType[0] = 1;
						pMovingType[1] = 2;
						pMovingType[2] = 3;
						pMovingType[3] = 15;
						pMovingType[4] = 19;
					}
					else if (k % 4 == 2) {
						pMovingType[0] = 9;
						pMovingType[1] = 6;
						pMovingType[2] = 3;
						pMovingType[3] = 12;
						pMovingType[4] = 13;
					}
					else if (k % 4 == 3) {
						pMovingType[0] = 7;
						pMovingType[1] = 8;
						pMovingType[2] = 9;
						pMovingType[3] = 13;
						pMovingType[4] = 10;
					}
					else if (k % 4 == 0) {
						pMovingType[0] = 7;
						pMovingType[1] = 4;
						pMovingType[2] = 1;
						pMovingType[3] = 10;
						pMovingType[4] = 16;
					}

					curRow = l + (pRowIndex / 4) * (k - 1) - 1;

					t[0] = p[curRow][pMovingType[0] - 1];
					t[1] = p[curRow][pMovingType[1] - 1];
					t[2] = p[curRow][pMovingType[2] - 1];
					t[3] = p[curRow][pMovingType[3] - 1];
					t[4] = p[curRow][pMovingType[4] - 1];
					p[curRow][pMovingType[0] - 1] = p[curRow][30 - pMovingType[2]];
					p[curRow][pMovingType[1] - 1] = p[curRow][30 - pMovingType[1]];
					p[curRow][pMovingType[2] - 1] = p[curRow][30 - pMovingType[0]];
					p[curRow][pMovingType[3] - 1] = p[curRow][30 - pMovingType[3]];
					p[curRow][pMovingType[4] - 1] = p[curRow][pMovingType[4] + 1];
					p[curRow][30 - pMovingType[0]] = t[2];
					p[curRow][30 - pMovingType[1]] = t[1];
					p[curRow][30 - pMovingType[2]] = t[0];
					p[curRow][30 - pMovingType[3]] = t[3];
					p[curRow][pMovingType[4] + 1] = t[4];

				}
				for(l = 0; l < 30; l++) if(p[curRow][l] != kai[l]) break;
				if(l == 30){
					printf("%d\n", j);
					goto next;
				}
			}
			pRowIndex /= 4;
			pat *= 4;
		}
		next:
		;
	}
	for (i = 0; i < 65536; i++) free(p[i]);
	free(p);

	return 0;
}
