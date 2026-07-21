#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#define swap(a,b) a^=b^=a^=b //二変数を入れ替え//
#define inf 1000000007
int main(void) {
	// your code goes here
	int h,w,i,j;
	char s[52][52];
	scanf("%d %d",&h,&w);
	scanf("%c",&s[0][0]);
	for(i=1;i<=h;i++){
		for(j=1;j<=w+1;j++){
			scanf("%c",&s[i][j]);
		}
	}
	for(i=0;i<=h+1;i++){
		s[i][0]='.';
		s[i][w+1]='.';
	}
	for(j=0;j<=w+1;j++){
		s[0][j]='.';
		s[h+1][j]='.';
		
	}
	for(i=1;i<=h;i++){
		for(j=1;j<=w;j++){
			if(s[i][j]=='#'&&s[i-1][j]=='.'&&s[i+1][j]=='.'&&s[i][j-1]=='.'&&s[i][j+1]=='.'){
				printf("No\n");
				return 0;
			}
		}
	}
	printf("Yes\n");
	return 0;

}
