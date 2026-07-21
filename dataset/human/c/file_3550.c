#include <stdio.h>
int main(void)
{
	int a,b,c,d[100],e,f,g,h;
	scanf("%d",&a);
	for (b=0;b<a;b++)
	{
		scanf("%d",&c);
		d[b]=c;
	}
	for (e=0;;e++)
	{
		f=0;
		for (b=0;b<a;b++)
		{
			if (e<=d[b])
			{
				f++;
			}
		}
		if (e>f)
		{
			break ;
		}
	}
	printf("%d\n",e-1);
	return 0;
}
