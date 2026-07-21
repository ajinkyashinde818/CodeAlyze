#include <stdio.h>
#define N 200000

int main()
{
	int n;
	int i=0;
	int R[N];
	int max;
	int min;

	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&R[i]);
	}

	for(i=1;i<n;i++){
		if(i==1){
			max = R[1]-R[0];
			min = R[0];
		}
		if(R[i]-min>max)max=R[i]-min;
		if(R[i]<min)min = R[i];
	}
	printf("%d\n",max);
	return 0;
}
