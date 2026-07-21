#include<stdio.h>
int main(void)
{
	int n,a[51],b[51],c[50],i,sat;
	scanf("%d",&n);
	for(i=1;i<=n;i++)	scanf("%d",&a[i]);
	for(i=1;i<=n;i++)	scanf("%d",&b[i]);
	for(i=1;i<=n-1;i++)	scanf("%d",&c[i]);
	sat=0;
	for(i=1;i<=n;i++){
		sat+=b[a[i]];
		if(a[i+1]-a[i]==1)	sat+=c[a[i]];
	}
	printf("%d\n",sat);
	return 0;
}
