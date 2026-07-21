#include <stdio.h>


int main(void)
{
	int n,m,tmpa,tmpb;
	scanf("%d %d\n",&n,&m);
	int a[n],b[n];
	for(int i=0;i<n;++i)
	{
		a[i]=0;
		b[i]=0;
	}
	for(int i=0;i<m;++i)
	{
		scanf("%d %d \n",&tmpa,&tmpb);
		if(tmpa==1)a[tmpb]=1;
		if(tmpb==n)b[tmpa]=1;
	}
	for(int i=0;i<n;++i){
		if(a[i]&b[i]){
			puts("POSSIBLE");
			return 0;
		}
	}
	puts("IMPOSSIBLE");
}
