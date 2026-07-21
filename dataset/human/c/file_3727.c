#include <stdio.h>
#include <string.h>
#define lop(i, n) for(i=0; i<n; i++)

int gcd(long int a, long int b){
	long int t;
	if(a<b){ t=a; a=b; b=t; }
	if(b<1)return -1;
	
	if(a%b==0)return b;
	else return gcd(b, a%b);
}

int main()
{
	long int a, b, tmp;
	scanf("%ld %ld", &a, &b);
	long int x = a * b;

	long int p=gcd(a, b);
	
	printf("%ld", x/p);
	
return 0;
}
