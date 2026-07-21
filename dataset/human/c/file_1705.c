#include<stdio.h>

int main(void)
{
	int i,n,a1=0,a2,b,c,sum=0;
	int bonus[21]={0};
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d",&a2);
		if(a2==a1+1)
			bonus[a1]=1;
		a1=a2;
	}
	for(i=0;i<n;i++){
		scanf("%d",&b);
		sum+=b;
	}
	for(i=1;i<=n-1;i++){
		scanf("%d",&c);
		if(bonus[i]==1)
			sum+=c;
	}
	printf("%d",sum);

	return 0;
}
