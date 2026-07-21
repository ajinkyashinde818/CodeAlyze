#include<stdio.h>
int main(void)
{
	int n,a,b,i,x[1001];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		a=0; b=0;
		scanf("%d %d",&a,&b);
		if(a%b!=0) x[i]=a%b;
		else x[i]=b;
	}
	for(i=0;i<n;i++) printf("%d\n",x[i]);
	return 0;
}
