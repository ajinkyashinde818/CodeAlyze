#include <stdio.h>

int main(int argc,char *argv[])
{
	long a,b,c,tasty;
	char ret;

	ret = scanf("%ld %ld %ld",&a,&b,&c);

	if (b > c) {
		tasty = b + c;
	} else {
		tasty = 2*b;
		c -= b;

		if (a > c) {
			tasty += c;
		} else if (a == c){
			tasty += a;
		} else {
			tasty += a+1;
		}
	}

	printf("%ld\n",tasty);

	
	return 0;
}
