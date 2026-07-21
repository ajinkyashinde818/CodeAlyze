#include<stdio.h>
#include<string.h>

int main()
{
	char a[1000005];
	scanf("%s",a);
	long long x=0,y=strlen(a)-1,lose=1;
	long long anc=0;
	while(x<=y)
	{
		if(a[x]!=a[y])
		{
			if(a[x]=='x')
			{
				anc++;
				x++;
			}
			else
				if(a[y]=='x')
				{
					anc++;
					y--;
				}
				else
				{
					lose=0;
					break;
				}
		}
		else
		{
			x++;
			y--;
		}
			
			
	}
		
	if(lose)
		printf("%lld\n",anc);
	else
		printf("-1\n");
	
	return 0;
}
