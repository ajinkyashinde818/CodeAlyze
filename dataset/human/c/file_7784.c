#include<stdio.h>
int main(void)
{
	int n,k,p,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		scanf("%d",&p);
		if(k%p==0){
			printf("%d\n",p);
		}
		else{
			printf("%d\n",k%p);
		}
	}
	return 0;
}
