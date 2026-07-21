#include <stdio.h>

int main(void){
	int n,k,min,max,i,l;
	
	scanf("%d",&n);
	scanf("%d",&l);
	min=l;

	for(i=2;i<=n;i++){
		scanf("%d",&k);
		if(i==2)
			max=k-l;
		if(max<k-min)
			max=k-min;
		if(min > k)
			min=k;
	}
	
	printf("%d\n",max);

	
	return 0;
}
