#include<stdio.h>
int main(void)
{
	int n,k,p,a[100],i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&k,&p);
		a[i]=k%p;
		if(a[i]==0){
			a[i]=p;
		}
	}
	for(i=0;i<n;i++){
		printf("%d\n",a[i]);
	}
	return 0;
}
