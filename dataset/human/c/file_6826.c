#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ll long long int
int compare_longlong(const void *a, const void *b) {long long *A = (long long *)a;long long *B = (long long *)b;if (*A > *B) return -1;if (*A < *B) return 1;return 0;}
int main(void){
	int n;
	scanf("%d",&n);
	ll a[3*n];
	for(int i=0;i<3*n;i++)scanf("%lld",&a[i]);
	qsort(a,3*n,sizeof(ll),compare_longlong);
	ll ans=0;
	for(int i=1;i<=2*n;i+=2){
		ans += a[i];
	}
	printf("%lld",ans);
	
	
	
	return 0;
}
