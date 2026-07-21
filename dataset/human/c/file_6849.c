#include <stdio.h>
#include <stdlib.h>
typedef long long ll;

ll compare_ll(const void *a, const void *b){
    return *(ll*)a - *(ll*)b;
}

int main(){
	int n;
	ll a[300001]={0}, ans=0;
	scanf("%d",&n);
	for(int i=0; i<3*n; i++){ scanf("%lld",&a[i]); }

    qsort( a, 3*n, sizeof(ll), compare_ll );
//	for(int i=0; i<3*n; i++){ ans += (a[1+i*3]); }
//	for(int i=n; i<2*n; i++){ ans += (a[i]);	 }
	for(int i=0; i<n;	i++){ ans += (a[n+i*2]); }
	printf("%lld\n",ans);
	return 0;
}
