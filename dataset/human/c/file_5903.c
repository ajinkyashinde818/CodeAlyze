#include <stdio.h>
#define N 200000

int main(void) {
	int n,R[N];
	int i,j,temp,max,min;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&R[i]);
	max=R[n-1]-R[n-2];
	min=R[n-1];
	for(i=n-2;i>=0;i--){
		if(max<min-R[i]) max=min-R[i];
		if(min<R[i]) min=R[i];
	}
	printf("%d\n",max);

	return 0;
}
