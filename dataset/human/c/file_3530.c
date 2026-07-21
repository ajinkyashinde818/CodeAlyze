#include <stdio.h>
int main(void)
{
	int k,a[101],n,m,s=0,ss;
	scanf("%d",&k);
	for(n=0;n<k;n++)
	{
		scanf("%d",&a[n]);
	}
	for(;;)
	{
		ss=0;
		for(m=0;m<k;m++)
		{
			if(a[m]>=s)
			{
				ss++;
			}
		}
		if(ss<s)
		{
			break;
		}
		s++;
	}
	printf("%d\n",s-1);
	return 0;
}
