#include <stdio.h>

int mod(int a, int b) {
	if (a == 0) {
		return b;
	}
	else {
		return mod(b%a, a);
	}
}

int main()
{
	long a,b;
	
	scanf("%ld", &a);
	scanf("%ld", &b);

	if (a > b) {
		long tmp = a;
		a = b;
		b = tmp;
	}
	
	int  c = mod(a, b);
	long d = a * b /c;
	printf("%ld",d);
	


	 
}
