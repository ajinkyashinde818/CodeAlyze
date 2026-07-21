#include <stdio.h>

int n, d, x, asdf, sum;

int main(){
	scanf("%d %d %d", &n, &d, &x);
	
	for(int i=0; i<n; i++){
		scanf("%d", &asdf);
		sum += (d-1)/asdf + 1;
	}
	
	printf("%d", sum + x);
	
	return 0;
}
