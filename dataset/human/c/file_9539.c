#include<stdio.h>

int main()
{
	int N;
	int D, X;
	int a[100];
	int sum = 0;
	int i;
	
	scanf("%d",&N);
	scanf("%d %d",&D,&X);
	for(i=0; i<N; i++){
		scanf("%d",&a[i]);
	}
	
	for(i=0; i<N; i++){
		sum += (D-1)/a[i] + 1;
	}
	
	sum += X;
	
	printf("%d",sum);
	
	return 0;
}
