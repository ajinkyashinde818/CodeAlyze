#include <stdio.h>

int main()
{
	int ia,ib;
	long int a,b,m,t;
	scanf( "%u", &ia );
	scanf( "%u", &ib );
	a = ia;
	b = ib;
	m = a*b;
	if (a<b) {
		t = a;
		a = b;
		b = t;
	}
	t = a%b;
	while (t!=0) {
		a = b;
		b = t;
		t = a%b;
	}
	printf("%ld",m/b);
}
