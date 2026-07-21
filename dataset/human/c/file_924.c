#include<stdio.h>
int N,E[100010][2],L,M,i,l,r,m;

int ch(int n)
{
	int i,t=1;
	for(i=0;i<N;i++)
		if(E[i][0]<=n&&E[i][1]>=n)
			t++;
	return t>=n;
}

int main()
{
	scanf("%d",&N);
	for(i=0;i<N;i++)
		scanf("%d%d",&E[i][0],&E[i][1]);
	for(i=N+1;i>=0;i--)
		if(ch(i))break;
	printf("%d\n",i-1);
	return 0;
}
