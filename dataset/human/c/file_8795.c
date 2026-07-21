#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int h, w;
	int s[50][50] = { 0 };
	int i , j , cnt;
	char str[50][50];

	scanf("%d %d", &h, &w);
	for (i = 0; i < h; i++) {
		scanf("%s", str[i]);
	}

	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			if (str[i][j] == '#') {
				s[i][j] = 1;
			}
			 //printf("%2d", s[i][j]);
		}
		//printf("\n");
	}

	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			if (s[i][j]) {
				//printf("h:%d %d %d %d ",h,i,j,s[i+1][j]);
				cnt = 0;
				if (i) {
					cnt += s[i - 1][j];
				}
				if (j) {
					cnt += s[i][j - 1];
				}
				if (i + 1 < h) {
					cnt += s[i + 1][j];
					//printf("\n%d", s[i + 1][j]);
				}
				if (j + 1 < w) {
					cnt += s[i][j + 1];
				}
				if (!cnt) {
					printf("No\n");
					return 0;
				}
			}
		}
	}
	printf("Yes\n");
	return 0;
}
