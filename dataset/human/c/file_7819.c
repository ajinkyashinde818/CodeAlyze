#include<stdio.h>
int main(void)
{
	int n,k,p,i,x,a;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&k,&p);
		if(k>p){
			if(k%p==0){
				x=p;
			}
			else{
				x=k%p;
			}
		}
		else{
			x=k;
		}
		printf("%d\n",x);
	}
	return 0;
}
