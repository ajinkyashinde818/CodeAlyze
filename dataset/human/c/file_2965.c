#include<stdio.h>

int main()
{
	int k,s,x,y,z,n;
	
	n=0;
	scanf("%d %d",&k,&s);
	
	for(x=0;x<=k;x++)
	{
		if(x>s) break;
		for(y=0;y<=k;y++)
			{if(y>s) break;
				if((s-x-y)<=k && s-x-y>=0)
				{
					n++;
				}		
			}
	}
	printf("%d",n);
}
