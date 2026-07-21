#include<stdio.h>
int main(void)
{
	int n,k[1000],p[1000],i,x,y,z;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&k[i],&p[i]);
	}
	for(i=0;i<n;i++){
		if(k[i]>p[i]){
			if(k[i]%p[i]!=0){
				x=k[i]%p[i];
				printf("%d\n",x);
			}
			else{
				printf("%d\n",p[i]);
			}
		}
		else{
			printf("%d\n",k[i]);
		}
	}
	return 0;
}
