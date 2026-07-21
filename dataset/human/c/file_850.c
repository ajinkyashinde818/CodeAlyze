#include <stdio.h>
long long n, i, j, ans;
int main(){
	scanf("%lld", &n);
	for(i=2; i*i<=n; i++){
		if(n%i) continue;
		for(j=i; j<=n; j*=i){
			if(n%j == 0){
				n /= j;
				ans++;
			}
		}
		while(n%i == 0) n /= i;
	}
	if(n > 1) ans++;
	printf("%lld\n", ans);
	return 0;
}
