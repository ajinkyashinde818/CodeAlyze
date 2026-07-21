#include <stdio.h>

int main(void)
{
	int a[10000],i=1,k=0,t;
	while(k==0){
		scanf("%d",&a[i]);
		if(a[i]==0){
			k=1;
		}else {
			i++;
		}
	}
	for(t=1;t<=i-1;t++){
		printf("Case %d: %d\n",t,a[t]);
	}
	return 0;
}
