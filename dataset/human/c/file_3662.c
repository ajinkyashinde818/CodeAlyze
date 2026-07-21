#include <stdio.h>
#include <limits.h>

int main(void) {
	int a,b,r,tmp;
	long long x;

	scanf("%d %d",&a,&b);
	x=(long long)a*b;
	
	if(a<b) {
		tmp = a;
		a = b;
		b = tmp;
	}

	r = a%b;
	while(r) {
		a = b;
		b = r;
		r = a%b;
	}
	printf("%lld",x/b);

	return 0;
}
