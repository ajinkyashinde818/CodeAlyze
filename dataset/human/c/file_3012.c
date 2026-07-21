#include<stdio.h>
int main()
{
	int k,n,a,b,st1,st2,max,i;
	while(~scanf("%d %d",&k, &n))
	{
		max = 0;
		scanf("%d", &a);
		st1=a;
		for(i=1; i<n; i++)
		{
			scanf("%d", &b);
			if(b-a>max)
				max = b-a;
			a = b;
		}
		st2 = k - a;
		if(st1+st2>max)
			max = st1 + st2;
		printf("%d\n", k - max);
	}
	return 0;
}
