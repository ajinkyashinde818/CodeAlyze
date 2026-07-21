#include<stdio.h>
#include<string.h>
#define MAX 10000
#define MAX2 1000000
int  sieve[MAX2+1];
int primes[MAX];
void create_primes() {
	memset(sieve, 0, sizeof(sieve));
	memset(primes, 0, sizeof(primes));
	int i,j,p;
	p = 0;
	for (i=2; i<MAX2; i++) {
		if (!sieve[i]) {
			primes[p++]=i;
			if (p>=MAX) break;
			for (j=i; j<MAX2+1; j+=i) sieve[j]=1;
		}
	}
}
int main()
{
	int n,i,res;
	create_primes();
	while (1) {
		scanf("%d", &n);
		if (n==0)break;
		res = 0;
		for (i=0;i<n;i++)res+=primes[i];
		printf("%d\n",res);
	}
	return 0;
}
