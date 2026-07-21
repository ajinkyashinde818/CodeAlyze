#include<stdio.h>
#define min(a,b)(((a)<(b))?(a):(b))
#define max(a,b)(((a)>(b))?(a):(b))
int LargestSquare(int size);
int w[1001][1001];
char str[1001][1001];
int main(void) {
	int n,ans=0;
	int i;
	while (1) {
		scanf("%d",&n);
		if (n == 0)break;
		for (i = 0; i < n; i++) {
			scanf("%s",str[i]);
		}
		ans = LargestSquare(n);
		printf("%d\n",ans);
	}
	return 0;
}

int LargestSquare(int size) {
	int  maxW=0;
	int i, j;
	for (i = 0; i < size; i++) {
			if (str[0][i] == '*')
				w[0][i] = 0;
			else
				w[0][i] = 1;
			if (str[i][0] == '*')
				w[i][0] = 0;
			else
				w[i][0] = 1;
	}
	for (i = 1; i < size; i++) {
		for (j = 1; j < size; j++) {
			if (str[i][j] == '*') {
				w[i][j] = 0;
			}else{
				w[i][j] = min(w[i - 1][j-1], min(w[i - 1][j], w[i][j - 1])) + 1;
				maxW = max(maxW,w[i][j]);
			}
		}
	}
	return maxW;
}
