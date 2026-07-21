#include<stdio.h>
int main(void)
{
	int h,w,c=0,i,j;
	char s[51][51];
	scanf("%d %d", &h, &w);
	for(i=0; i<h; i++)
	scanf("%s", &s[i]);
	for(i=0; i<h; i++)
	{
		for(j=0; j<w; j++)
		{
			if(s[i][j]=='#')
			{
				if(s[i][j-1]=='.'&&s[i][j+1]=='.'&&s[i-1][j]=='.'&&s[i+1][j]=='.')
				c=1;
			}
		}
	}
	if(c==0)
	printf("Yes\n");
	else
	printf("No\n");
	
	return 0;
}
