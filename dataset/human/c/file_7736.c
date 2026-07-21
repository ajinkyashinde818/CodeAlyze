#include<stdio.h>
int main(void)
{
	int i,n,k,p,a[1000];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&k,&p);
		if(k%p==0) a[i]=p;
		else a[i]=k%p;
	}
	for(i=0;i<n;i++) printf("%d\n",a[i]);
	return 0;
}
