#include <stdio.h>

int main(void) {
	long int n,m; scanf("%ld %ld",&n,&m);
	long int ary[n+1];
	for (long int i=0; i<=n; i++) {
		ary[i]=1;
	}
	long int l; 
	for (long int i=0; i<m; i++) {
		scanf("%ld",&l); ary[l]=0;
	}
	for (long int i=2; i<=n; i++) {
		if (ary[i]!=0) ary[i]=(ary[i-2]+ary[i-1])%1000000007;
	}
	printf("%ld\n",ary[n]);
	return 0;
}
