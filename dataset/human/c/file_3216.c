#include <stdio.h>

int main(){
	int k,n;
	scanf("%d%d",&k,&n);
	int a[n+1];
	for(int i=0;i<n;++i){
		scanf("%d",&a[i]);
	}

	a[n] = k + a[0];

	int candidate = 0;
	for(int i = n; i > 0; i--){
		a[i] -= a[i-1];
		candidate = (a[i] > candidate) ? a[i] : candidate;
	}

	printf("%d",k - candidate);

	return(0);
}
