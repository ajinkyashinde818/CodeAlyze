#include<stdio.h>
int main(void)
{
	int n,k,p,a,i,c,x[1000];
	c=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&k,&p);
		if(k%p==0){
			x[i]=p;
		}
		else{
			a=k%p;
			x[i]=a;
		}
	}
	for(i=0;i<n;i++){
		printf("%d\n",x[i]);
	}
	return 0;
}
