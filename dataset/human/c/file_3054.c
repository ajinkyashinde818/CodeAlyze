#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define rep(i,l,n) for(int (i)=(l);(i)<(n);(i)++)
#define min(a,b) (a)<(b)?(a):(b)
#define max(a,b) (a)>(b)?(a):(b)

int int_cmp(const void*,const void*);

int main(){
	int K,N; scanf("%d %d",&K,&N);
	int a[N];
	rep(i,0,N) scanf("%d",&a[i]);
	int max = K+a[0]-a[N-1];
	rep(i,1,N) max = max(max,a[i]-a[i-1]);
	printf("%d",K-max);
	return 0;
}
