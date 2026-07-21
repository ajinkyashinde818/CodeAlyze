#include<stdio.h>
int main()
{
	int n,k[1000],p[1000],i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&k[i],&p[i]);
	}
	/*for(i=0;i<n;i++){
		printf("i=%d k=%d p=%d\n",i,k[i],p[i]);
	}*/
	for(i=0;i<n;i++){
		if(k[i]>p[i]){
			if(k[i]%p[i]!=0){
				printf("%d\n",k[i]%p[i]);
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
