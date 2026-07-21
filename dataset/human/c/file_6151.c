#include <stdio.h>

int main(){
	int i,n;
	scanf("%d",&n);
	int r[n],min[n],max[n],Max=-1000000000;
	for(i=0;i<n;i++){
		scanf("%d",&r[i]);
    }

	min[0]=r[0];
	max[0]=r[n-1];
	for(i=1;i<n-1;i++){
		if(r[i] < min[i-1]){min[i]=r[i];}else{min[i]=min[i-1];}
		if(r[n-1-i] > max[i-1]){max[i]=r[n-1-i];}else{max[i]=max[i-1];}
	}
	for(i=0;i<n-1;i++){
		if(max[n-2-i]-min[i] > Max){Max=max[n-2-i]-min[i];}
	}
	printf("%d\n", Max);

	return 0;
}
