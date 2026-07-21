#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <string.h>
long long abs(long long);
int main(){
	long long n;
	scanf("%lld", &n);
	long long a[200010];
	long long subsum[200010];
	long long i, j;
	long long t;
	long long minimum=214748364700000;
	long long sum=0;
	long long x=0;
	for(i=1;i<=n;i++){
		scanf("%lld", &a[i]);
		sum+=a[i];
	}
	for(i=1;i<=n-1;i++){
		x+=a[i];
		subsum[i]=abs(2*x-sum);
		if(subsum[i]<minimum) minimum=subsum[i];
	}
	printf("%lld", minimum);
	return 0;
}
long long abs(long long a){
	if(a>=0) return a;
	else return -a;
}
