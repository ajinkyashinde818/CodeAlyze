#include <stdio.h>

int main(void){
	long x, r, count = 0;

	scanf("%ld", &x);

	r = x % 11;
	if(r > 6)
		count = 2*(x / 11) + 2;
	else if(r > 0)
		count = 2*(x / 11) + 1;
	else
		count = 2*(x / 11);
	printf("%ld", count);

	return 0;
}
