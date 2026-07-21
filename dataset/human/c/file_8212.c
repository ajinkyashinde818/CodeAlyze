#include <stdio.h>
 
int main(void)
{
	int a, b, c, d, menseki1, menseki2;
	scanf( "%d %d %d %d", &a, &b, &c, &d );
	menseki1 = a * b;
	menseki2 = c * d;
	if( menseki1 > menseki2 ){
		printf( "%d\n", menseki1 );
	}
	if( menseki2 > menseki1 ){
		printf( "%d\n", menseki2 );
	}
	if( menseki1 == menseki2 ){
		printf( "%d\n", menseki1 );
	}
	return 0;
}
