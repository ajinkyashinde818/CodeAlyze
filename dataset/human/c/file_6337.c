#include <stdio.h>
#include <limits.h>

int main(){
	int n,z,i,R[200000],max=INT_MIN,min=INT_MAX;
	scanf("%d",&n);
	for(i=0 ; i<n ; i++)
		scanf("%d",&R[i]);
	for(i=0 ; i<n ; i++){
		if(max<R[i]-min) max=R[i]-min;
		if(min>R[i]) min=R[i];
	}
	z=max;
	printf("%d\n",z);
	return 0;
}
