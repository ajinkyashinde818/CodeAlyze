#include <stdio.h>
#include <limits.h>

int main(int argc, char argv[]){
	int n;
	int R;

	scanf("%d",&n);
	int i;
	int m;
	scanf("%d",&R);
	int min=R, max=INT_MIN;
	m=max;
	for(i=1;i<n;i++){
		scanf("%d",&R);
		m = R - min;
		if(min > R)min = R;
		if(m > max)max = m;
//		printf("min = %d,max = %d\n",min,max);
	}
	printf("%d\n",max);

	return 0;
}
