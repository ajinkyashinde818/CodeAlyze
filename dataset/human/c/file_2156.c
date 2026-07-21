#include <stdio.h>

int main() {
	long long n;
	scanf("%lld", &n);
	long long ans = 0;
	if(n%2==1){
		ans=0;
	}else{
		for (long long i = 10; i <= n; i=i*5) {
			ans+=n/i;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
