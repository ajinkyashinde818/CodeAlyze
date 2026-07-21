#include <stdio.h>
#define MAX_N 200000

int main(){
	int i,j;
	int n,maxv,min;
	int r[MAX_N];
	scanf("%d",&n);
	for(i=0; i<n; i++) scanf("%d",&r[i]);

	min  = r[0];
	maxv = r[1] - min;
	for(j=1; j<n; j++){
		if(maxv < r[j] - min) maxv = r[j] - min;
		if(min > r[j]) min = r[j];
	}

	printf("%d\n",maxv);

	return 0;
}
