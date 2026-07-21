#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXVALUE 99999999

int main(void) {
	int N,M,X;
	int price[12];
	int rikai[12][12];
	int i,j,k,min,tmp, totalprice;
	int Ms[12];
	
	scanf("%d %d %d^n", &N,&M,&X);
	for (i = 0; i < N; i++) {
        scanf("%d", &price[i]);
		for (j = 0; j < M; j++) {
			scanf("%d", &rikai[i][j]);
		}
	}
	
	// 本を買う買わないの組み合わせでループ
	min = MAXVALUE;
	tmp = (int)pow(2, N);
	for (i = 0; i < tmp; i++) {
		totalprice = 0;
		memset(Ms, 0x00, sizeof(Ms));
		for (j = 0; j < N; j++) {
			if ((i >> j & 1) == 1) {
				totalprice += price[j];
				for (k = 0; k < M; k++) {
					Ms[k] += rikai[j][k];
				}
			}
		}
		// アルゴリズムの理解度チェック
		for (k = 0; k < M; k++) {
			if (Ms[k] < X) {
				totalprice = MAXVALUE;
				break;
			}
		}
		
		if (totalprice < min) {
			min = totalprice;
		}
	}
	
    if (min == MAXVALUE) min = -1;
	printf("%d\n", min);
	return(0);
}
