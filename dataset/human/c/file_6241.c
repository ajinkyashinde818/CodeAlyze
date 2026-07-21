#include <stdio.h>
#define N 200000

int Max(int i,int j){return i>j?i:j;}
int Min(int i,int j){return i<j?i:j;}

int main()
{
	int i,n,a[N];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	int maxv=-2000000000;
	int minv=a[0];
	for(i=1;i<n;i++)
	{
		maxv=Max(maxv,a[i]-minv);
		minv=Min(minv,a[i]);
	}
	printf("%d\n",maxv);
}
