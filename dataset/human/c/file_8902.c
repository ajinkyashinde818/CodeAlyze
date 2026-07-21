#include<stdio.h>

int main(void)
{
	int i,j,h,w,c=0;
	scanf("%d%d",&h,&w);
	char g[h+2][w+2];
	for(i=1;i<=h;i++)
		scanf("%s",g[i]+1);
	
	for(i=0;i<=w+1;i++){
		g[0][i]='.';
		g[h+1][i]='.';
	}
	for(i=0;i<=h+1;i++){
		g[i][0]='.';
		g[i][w+1]='.';
	}

	for(i=1;i<=h;i++){
		for(j=1;j<=w;j++){
			if(((g[i][j]=='#' && g[i-1][j]=='.')&&(g[i][j-1]=='.' && g[i][j+1]=='.')) && g[i+1][j]=='.')
				c=1;
		}
	}
	if(c==1)
		printf("No");
	else
		printf("Yes");
	return 0;
}
