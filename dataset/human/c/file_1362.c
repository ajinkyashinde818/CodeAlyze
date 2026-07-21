#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int main(void) {
	// your code goes here
	int n,m,i,a,b,f = 0;
	scanf("%d%d",&n,&m);
	int*x = (int*)malloc(sizeof(int)*(n+2));
	memset(x,n+2,0);
	for(i = 0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		if(a==1&& b!=n)
			{
				if(x[b] ==1)
					f = 1;
				else 
				x[b]=1;
				
			}
		else if(b==n&& a!=1)
		{
			if(x[a]==1)
				f = 1;
			else 
			x[a]=1;
		}
	}
		if(!f)printf("IM");
	printf("POSSIBLE");
	return 0;
}
