#include<stdio.h>
int main(void)
{
	int w,h,n,x[10000],y[10000],a,b,m=0,i;
	scanf("%d %d %d", &w, &h, &n);
	for(i=0; i<n; i++)
	scanf("%d %d", &x[i], &y[i]);
	for(i=1; i<n; i++)
	{
		a=x[i]-x[i-1];
		b=y[i]-y[i-1];
		if(a*b>0)
		{
			if(a>0)
			{
				if(a>b)
				m+=a;
				else
				m+=b;
			}
			if(a<0)
			{
				a*=-1;
				b*=-1;
				if(a>b)
				m+=a;
				else
				m+=b;
			}
		}
		else
		{
			if(a<0)
			a*=-1;
			if(b<0)
			b*=-1;
			m+=a+b;
		}
	}
	printf("%d\n", m);
	
	return 0;
}
