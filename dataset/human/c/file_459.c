#include<stdio.h>
void swap(int&x,int&y){int t=x;x=y;y=t;}
const int Maxn=200010;
int n,a[Maxn],b[Maxn],c[Maxn],d[Maxn],ld=0;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),c[a[i]]++;
	for(int i=1;i<=n;i++)scanf("%d",&b[i]),c[b[i]]++;
	for(int i=1;i<=n;i++)if(c[i]>n)return puts("No"),0;
	puts("Yes");
	for(int i=1;i<=n/2;i++)swap(b[i],b[n-i+1]);
	int L=-1,R,x;
	for(int i=1;i<=n;i++)
	if(a[i]==b[i])
	{
		L=i;x=a[i];
		for(int j=i;j<=n;j++)
		if(a[j]==b[j])R=j;
		break;
	}
	if(L!=-1)
	{
		for(int i=1;i<=n;i++)
		if(a[i]!=x&&b[i]!=x)d[++ld]=i;
		for(int i=L;i<=R;i++)
		swap(b[i],b[d[ld--]]);
	}
	for(int i=1;i<=n;i++)printf("%d ",b[i]);
 }
