#include <stdio.h>
#include <math.h>

int minnum(int a, int b){
	if(a>b)	return b;
	else return a;
}

int main(void){
	long long int a,b;
	long long int saisyo;
	scanf("%lld %lld", &a, &b);
	for(int i=minnum(a,b);i>=1;i--){
		if(a%i==0 && b%i==0){
			saisyo=(long long int)i;
			break;
		}
	}
	printf("%lld", a*b/saisyo);

}
