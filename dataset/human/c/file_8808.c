#include <stdio.h>

int main()
{
	int i, j,H, W, flag = 1;
	char S[50][51] = {};
	char newS[52][52] = {};
	
	scanf("%d %d",&H,&W);
	for(i = 0; i< H; i++) scanf("%s",S[i]);
	for(i = 0; i <= W; i++)
	{
		newS[0][i] = '.';
		newS[H+1][i] = '.';
	}
	newS[0][W+1] = '\n'; newS[H+1][W+1] = '\n';
	
	for(i = 1; i <= H; i++)
	{
		sprintf(newS[i],".%s\n",S[i-1]);
	}
	
	for(i=1; i<=H; i++)
	{
		for(j=1;j<W;j++)
		{
			if(newS[i][j]=='#' && newS[i-1][j]!='#' && newS[i+1][j]!='#' && newS[i][j+1]!='#' && newS[i][j-1]!='#') flag = 0;
			if(flag == 0) break;
		}
		if(flag == 0) break;
	}
	
	printf("%s\n",(flag==0)? "No":"Yes");
	return 0;
}
