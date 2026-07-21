#include<stdio.h>
int main(void)
{
	int i,j;
	int n;
	int maxv=-1000000001,minv;
	
	scanf("%d",&n);
	int A[n];
	for (i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	minv=A[0];
	
	for (i=1;i<n;i++){
		if (maxv<A[i]-minv){
			maxv=A[i]-minv;
		}
		if (minv>A[i]){
			minv=A[i];
		}
	}
	
	printf("%d\n",maxv);
	
	return 0;
}
