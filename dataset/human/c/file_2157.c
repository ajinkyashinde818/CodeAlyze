#include <stdio.h>
#include <math.h>

int main(void){
	long long int n;
	long long int ans=0;
	scanf("%lld", &n);
	
	if(n%2==1)	printf("0");
	else{
		for(int i=1; i <= (int)(log10l((long double)n/(long double)2.0)/log10l(5.0));i++){
			ans += (n-n%(long long int)(pow(5,i)*2) ) / (long long int)(pow(5,i)*2);
		}
      printf("%lld", ans);
	}
	return 0;
}
