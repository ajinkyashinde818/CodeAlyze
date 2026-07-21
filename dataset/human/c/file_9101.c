#include<stdio.h>

int main(void)
{
	int i,n,k,tall;
	
	scanf("%d%d",&n,&k);
	
	int count=0;
	
	for(i=0;i<n;i++){
		scanf("%d",&tall);
		if(tall>=k)
			count++;
	}
	
	printf("%d",count);
	return 0;
}
