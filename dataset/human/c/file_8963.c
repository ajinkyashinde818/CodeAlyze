// Aizu Vol-1 0158: Collatz's Problem
// 2017.8.2

#include <stdio.h>
#include <stdlib.h>

char *gets(char *);
char buf[50];

int main()
{
	int n, k;

	while (gets(buf) != NULL) {
		if (!(n = atoi(buf))) break;
		k = 0;
		while (n > 1) {
			if (n & 1) n = n + ((n+1)>>1), k++;
			else n >>= 1;
			k++;
		}
		printf("%d\n", k);
	}
	return 0;
}
