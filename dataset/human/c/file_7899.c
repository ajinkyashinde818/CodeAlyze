#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long gcd(long a, long b){
	long t;
	if(a<b){
		t=a; a=b; b=t;
	}
	t=a%b;
	while(t!=0){
		a=b; b=t; t=a%b;
	}
	return b;
}

int main(void){
	int n, m, i;
	scanf("%d%d", &n, &m);

	int a;
	scanf("%d", &a);
	a/=2;
	int t=a&(-a);
	int l=a;
	for(i=1; i<n; i++){
		scanf("%d", &a);
		a/=2;
		int T=a&(-a);
		int b = l/gcd(l, a);
		if(t!=T || __builtin_smul_overflow(b, a, &l)) break;
	}
	if(i<n){
		puts("0");
		return 0;
	}
	printf("%d\n", (m/l+1)/2);
}
