// Volume1-0158 Collatz's Problem

#include <stdio.h>

#define in(x) scanf("%d", &x)

int step;

void collatz(int n)
{
	if ((n % 2) == 1 && n > 1){
		step++;
		collatz(3 * n + 1);
	}
	else if (n % 2 == 0){
		step++;
		collatz(n / 2);
	}
}

int main(void)
{
	int n;
	
	while (in(n) != EOF && n != 0){
		step = 0;
		collatz(n);
		printf("%d\n", step);
	}
	
	return (0);
}
