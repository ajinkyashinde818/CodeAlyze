#include<stdio.h>
int d[60][200010];
int main(){
	long long n,k;
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&d[0][i]);
	for(int x=1;x<60;x++)for(int i=1;i<=n;i++)d[x][i]=d[x-1][d[x-1][i]];
	int pos=1;
	for(int x=59;x>=0;x--)if((k>>x)&1)pos=d[x][pos];
	printf("%d",pos);
}
