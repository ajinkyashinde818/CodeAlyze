#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>


long long inv(long long i, long long p){
	long long retval = 1;
	long long multiple_num = i;
	long long power = p-2;
	while (power) {
		//printf("power=%lld\n",power);
		if ((power&1)!=0){
			//printf("multple_num=%lld\n",multiple_num);
			retval *= multiple_num%p;
			retval %= p;
			//printf("retval=%lld\n",retval);
		}
		multiple_num *= multiple_num;
		multiple_num %=p;
		power = (power>> 1);
	}
	return retval;
}

/*int main (){
	printf("%lld\n", inv(2,1000000007));
	return 0;
}*/
int main (){
	long long p = 1000000007;
	long long X;
	long long Y;
	scanf("%lld",&X);
	scanf("%lld",&Y);
	if ((2*Y-X)%3!=0 || (2*X-Y)%3!=0 || (2*Y-X)<0 || (2*X-Y)<0){
		printf("0\n");
		return 0;
	}
	long long a = (2*X-Y)/3;
	long long b = (2*Y-X)/3;
	//printf("a=%lld\n",a);
	//printf("b=%lld\n",b);
	// a+bCaを求める
	long long ans =1;
	for (long long i=b+1; i<=b+a; i++){
		ans *= i;
		ans %= p;
	}
	//printf("ans_temp=%lld\n",ans);
	for (long long i=1; i<=a; i++){
		//printf("inv(%lld, %lld)=%lld\n",i,p,inv(i, p));
		ans *= inv(i, p);
		ans %= p;
	}
	printf("%lld\n",ans);
	return 0;
}
