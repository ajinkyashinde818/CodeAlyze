#include<stdio.h>
int main(void)
{
	int n,k[1000],p[1000],i,a;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&k[i],&p[i]);
		if(k[i]>=p[i]){
			a=k[i]%p[i];
			if(a==0){
				printf("%d\n",p[i]);
			}
			if(a!=0){
				printf("%d\n",a);
			}
		}
		else if(k[i]<=p[i]){
			printf("%d\n",k[i]);
		}
	}
	return 0;
}
