#include<stdio.h>
int main(void)
{
	int n,k,p,x,i;
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d %d",&k,&p);
		if(k%p==0){
			printf("%d\n",p);
		}
		else{
			x=k%p;
			printf("%d\n",x);
		}
	}
	
	return 0;
}
