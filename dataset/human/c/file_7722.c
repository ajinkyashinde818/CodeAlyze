#include <stdio.h>

int main(int argc, char *args[])
{
	int x[10001]; 
	int c;
	int i;

	for( i=0; i<=10000; i++ ) {
		scanf("%d", &x[i]);

		if( x[i] == 0 ) {
			break;
		}

	}

	for( c=0; c < i; c++ ) {
		printf("Case %d: %d\n", c+1, x[c]);
	}

	return 0;
}
