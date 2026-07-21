#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.141592653589793
#define MOD 1000000007


int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	int lar, sma;
	if(a>b){
		lar = a;
		sma = b;
	}
	else{
		lar = b;
		sma = a;
	}
	long int ans = lar;
	while(ans%sma != 0){
		ans += lar;
	}

	printf("%ld\n", ans);

	return 0;
}
