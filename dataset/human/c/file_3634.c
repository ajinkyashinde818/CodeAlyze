#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>


int main(){
	
	long long a,b,n;
	scanf("%lld %lld",&a,&b);
	for( long long i=a; i>0; i--) {
		if( a%i == 0 && b%i == 0) {
			n=i;
			break;
		}
	}
	printf("%lld",a*b/n);
	return 0;
	
}
