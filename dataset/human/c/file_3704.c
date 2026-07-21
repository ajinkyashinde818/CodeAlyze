#include<stdio.h>
#include<string.h>

long gcd(int n, int m);
int main(void)
{
	long n, m;
	scanf("%ld%ld", &n, &m);
	printf("%ld", m*n/gcd(n, m));

	return 0;
}
long gcd(int n, int m)
{
	if(n<m) n^=m^=n^=m;
	if(n%m==0) return m;
	return gcd(m, n%m);
}
