#include <stdio.h>
int main()
{
	int k,i,ii,iii,s,cnt=0;
	scanf("%d %d",&k,&s);
	for(i=0; i<=k; ++i)
	{
		for(ii=0; ii<=k; ++ii)
		{
			iii=s-i-ii;
			if(0<=iii && iii<=k) cnt=cnt+1;
		}
	}
	printf("%d\n",cnt);
	return 0;
}
