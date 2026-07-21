#include<stdio.h>
int main(void)
{
	int i,N,A[21],B[21],C[20];
	int sum=0;
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
	}
	for(i=0;i<N;i++)
	{
		scanf("%d",&B[i]);
	}
	for(i=0;i<N-1;i++)
	{
		scanf("%d",&C[i]);
	}
	for(i=0;i<N;i++)
	{
		if(A[i]==A[i+1]-1)
		sum=B[A[i]-1]+C[A[i]-1]+sum;
		else
		sum=B[A[i]-1]+sum;
	}
	printf("%d",sum);
	return 0;
	
}
