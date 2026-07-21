#include <stdio.h>

int main(void)
{
	int N;
	int i, j, max, min;
	scanf("%d", &N);
	int a[N];
	for(i=0; i<N; i++){
		scanf("%d", &a[i]);
	}
	max=a[1]-a[0];
	min=a[0];
	for(j=1; j<N; j++){
		if(max>=a[j]-min) ;
		else max=a[j]-min;
		
		if(min<=a[j]) ;
		else min=a[j];
	}
	
	printf("%d\n", max);
	
	return 0;
}
