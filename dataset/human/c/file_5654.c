#include <stdio.h>
#include <math.h>

int main(void){
	long long  x;
	double cnt;
	
	scanf("%lld", &x);
	
	cnt = (double)x/11.0*2.0;
	
	cnt = ceil(cnt);
	
	if (cnt*11.0/2.0-5.0 >= x) cnt--;
	
	printf("%lld\n", (long long)cnt);
	
	return 0;
}
