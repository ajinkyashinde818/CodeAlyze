#include <stdio.h>

int main(void)
{
	int max=0,a,b,k,n,i,c;
	scanf("%d",&k);
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a);
		if(i==0){
			b=a;
			c=a;
		}
		else{
			if(a-c>max)max=a-c;
			c=a;
		}
	}
	if(k-a+b>max)max=k-a+b;
	printf("%d",k-max);
	return 0;
}
