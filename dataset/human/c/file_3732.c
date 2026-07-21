#include <stdio.h>
int main() {
	long a,b,c,tmp,r,i;
	scanf("%ld %ld",&a,&b);
	c=a*b;
	if(a<b) {
		tmp=a;
		a=b;
		b=tmp;
	}
	r=a%b;
	while(r!=0) {
		a=b;
		b=r;
		r=a%b;
	}
	printf("%ld",c/b);
	return 0;
}
