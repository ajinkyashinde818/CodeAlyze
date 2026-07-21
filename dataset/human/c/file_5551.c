#include <stdio.h>
#define SIZE 10000

int p[SIZE];

void init();
void show();
int isPrime(int n);
long prime_sum(int n);

int main(int argc, const char *argv[])
{
	int n;
	init();
	
	while(scanf("%d", &n)!=EOF){
		if(!n) break;
		printf("%ld\n", prime_sum(n));
	}
	return 0;
}

void init()
{
	int i, j;
	p[0] = 2;
	for(i=1, j=3; i<SIZE; j+=2){
		if(!isPrime(j)) continue;
		p[i++] = j;
	}
}

int isPrime(int n)
{
	int i;
	if(n<=1) return 0;
	else if(n==2) return 1;
	else if(n%2==0) return 0;
	else
		for(i=3; i*i<=n; i++)
			if(n%i==0) return 0;
	return 1;
}

long prime_sum(int n)
{
	int i;
	long s = 0;
	for(i=0; i<n; i++)
		s += p[i];
	return s;
}
