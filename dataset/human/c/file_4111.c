#include <stdio.h>

int main(void)
{
	int a,b,k,i;
	scanf("%d %d %d",&a,&b,&k);
	int ans[101],j=0;
	for(i=1;i<=100;i++){
		if((a%i==0) && (b%i==0)){
			//printf("%d\n",i);
			ans[j]=i;
			j++;
		}
	}
	printf("%d\n",ans[j-k]);
	return 0;
}
