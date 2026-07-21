#include <stdio.h>

int main(){
	int h,w;
	char color[52][52];
	scanf("%d %d",&h,&w);
	for(int i=0;i<h+2;i++)
	{
		for(int j=0;j<w+2;j++)
		{
			if(i==0||j==0||i==h+1||j==w+1)
			{
				color[i][j]='.';
			}else if(j == 1)
			{
				scanf("%s",color[i]);
			}
				
				if(i>1 && j != 0 && j != w+1 && color[i][j]=='.' && color[i-1][j]=='#' && color[i-2][j]=='.' && color[i-1][j-1]=='.' && color[i-1][j+1]=='.')
				{
					printf("No");
					return 0;
				}
			
		}
	}
	printf("Yes");
	return 0;
}
