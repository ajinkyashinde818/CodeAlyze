#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#define P 1000000007

int comp(const void *a, const void *b){return *(int*)a-*(int*)b;}

int main(void){
	int h, w, i, j;
	char s[50][51];
	scanf("%d%d", &h, &w);
	for(i=0; i<h; i++){
		scanf("%s", s[i]);
	}
	for(i=0; i<h; i++){
		for(j=0; j<w; j++){
			if(s[i][j]!='#') continue;
			if(i!=0 && s[i-1][j]=='#') continue;
			if(i!=h-1 && s[i+1][j]=='#') continue;
			if(j!=0 && s[i][j-1]=='#') continue;
			if(j!=w-1 && s[i][j+1]=='#') continue;
			puts("No");
			return 0;
		}
	}
	puts("Yes");
}
