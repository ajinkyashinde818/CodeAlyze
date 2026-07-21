#include <stdio.h>

int main(void){
	long int a[1000000];
	int j,n,max=0,answer,min;
	long int i;
	// for(i=0;i<200000;i++){
	// 	// a[i]=0;
	// 	b[i]=0;
	// }
	scanf("%d",&n);
	scanf("%ld",&a[0]);
	scanf("%ld",&a[1]);
	if(a[0]>a[1]) min=a[1];
	else min = a[0];
	max = a[1]-a[0];
	// printf("%d\n",n);
	for(i=2;i<n;i++){
		scanf("%ld",&a[i]);
		if(max < a[i]-min) max = a[i]-min;
		if(a[i]<min) min=a[i];
	}
	printf("%d\n",max);
	return 0;
}
