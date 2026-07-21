#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	long int i, j, k, l;
	long int h, w, n;
	long int flg_first;
	long int left, right, top, under;
	long int count = 1;
	long int masu[400][400] = {{0}};
	char str[400][400];
	
	scanf("%ld%ld%ld", &h, &w, &n);
	
	for(i = 0; i < h; i++) {
		scanf("%s", str[i]);
	}
	
	for(i = 0; i < h; i++) {
		for(j = 0; j < w; j++) {
			if(str[i][j] =='#') {
				top = under = i;
				left = right = j;
				for(k = j - 1; k >= 0; k--) {
					if( (str[i][k] == '#') || (masu[i][k] >= 1) ) {
						left = k + 1;
						break;
					}
				}
				if(k <= -1) {
					left = 0;
				}
				
				for(k = j + 1; k < w; k++) {
					if( (str[i][k] == '#') || (masu[i][k] >= 1) ) {
						right = k - 1;
						break;
					}
				}
				if(k >= w) {
					right = w - 1;
				}
				
				flg_first = 0;
				for(k = i - 1; k >= 0; k--) {
					for(l = left; l <= right; l++) {
						if( (str[k][l] == '#') || (masu[k][l] >= 1) ) {
							top = k + 1;
							flg_first = 1;
							break;
						}
					}
					if(flg_first == 1) {
						break;
					}
				}
				if(k <= -1) {
					top = 0;
				}
				
				flg_first = 0;
				for(k = i + 1; k < h; k++) {
					for(l = left; l <= right; l++) {
						if( (str[k][l] == '#') || (masu[k][l] >= 1) ) {
							under = k - 1;
							flg_first = 1;
							break;
						}
					}
					if(flg_first == 1) {
						break;
					}
				}
				if(k >= h) {
					under = h - 1;
				}
				//printf("%ld %ld %ld %ld\n", top, under, left, right);
				for(k = top; k <= under; k++) {
					for(l = left; l <= right; l++) {
						masu[k][l] = count;
					}
				}
				count++;
				//j = right;
			}
		}
	}
	
	for(i = 0; i < h; i++) {
		for(j = 0; j < w; j++) {
			printf("%ld ", masu[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
