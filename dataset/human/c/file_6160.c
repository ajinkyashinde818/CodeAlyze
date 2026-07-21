#include <stdio.h>
int main (void){
	int n, i, j, maxv, minv, a[200000];

	scanf("%d", &n);
	
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	
	maxv = a[1]-a[0];
	minv = a[0];
	
	for(j=1; j<n; j++){
		if(maxv < a[j]-minv) maxv = a[j]-minv;
		if(minv > a[j]) minv = a[j];
	}
	
	printf("%d\n", maxv);
	
	return 0;
}
