#include<stdio.h>
int N,a,b,x[100002],i;
int main()
{
	for(i=!scanf("%d",&N);i<N;++i)
	{
		scanf("%d%d",&a,&b);
		++x[a-1];
		--x[b];
	}
	for(a=b=i=0;i<=N;++i)
		if(b+=x[i],b>=i)
			a=i;
	printf("%d\n",a);
	return 0;
}
