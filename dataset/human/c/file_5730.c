#include<math.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
int maxa(int x,int y)
{
	if(x>y)
		return x;
	return y;
}
int mina(int v,int u)
{
	if(v<u)
		return v;
	return u;
}
int main()
{
	int t,n,i,maxv=-2000000000,R[200010];
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&R[i]);
	int minv=R[1];
	for(i=2;i<=n;i++)
	{
		maxv=maxa(maxv,R[i]-minv);
		minv=mina(minv,R[i]);
	}
	printf("%d\n",maxv);
	return 0;
}
