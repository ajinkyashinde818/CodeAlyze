#include<stdio.h>
#include<string.h>

#define INF 1001001001
#define MAX_DIGIT 1000000+1
char s[MAX_DIGIT+5];
int dp[MAX_DIGIT+5][2];

int min(int a, int b){
	return (a < b) ? a : b;
}

int main(){
	int len;
	int i, j, ni, nj;
	int x, a, b;

	s[0] = '0';
	scanf("%s", s+1);
	len = strlen(s);
	for(i=0; i<len+1; i++){
		for(j=0; j<2; j++){
			dp[i][j] = INF;
		}
	}
	dp[0][0] = 0;
	for(i=0; i<len; i++){
		for(j=0; j<2; j++){
			x = s[len-1-i] - '0';
			x += j;
			for(a=0; a<10; a++){
				ni = i + 1;
				nj = 0;
				b = a - x;
				if(b < 0){
					nj = 1;
					b += 10;
				}
				dp[ni][nj] = min(dp[ni][nj], dp[i][j]+a+b);
			}
		}
	}

	printf("%d", dp[len][0]);

	return 0;
}
