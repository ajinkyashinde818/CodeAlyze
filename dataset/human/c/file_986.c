#include <stdio.h>

int main(void)
{
	int e, y;
	
	scanf( "%d %d", &e, &y );
	switch( e )
	{
		case 0:
			if( y <= 1911 )
			{
				printf( "M%d\n", y - 1868 +1 );
			}
			else if( y <= 1925 )
			{
				printf( "T%d\n", y - 1912 +1 );
			}
			else if( y <= 1988 )
			{
				printf( "S%d\n", y - 1926 +1 );
			}
			else
			{
				printf( "H%d\n", y - 1989 +1 );
			}
			break;
		case 1:
			printf( "%d\n", y + 1868 -1 );
			break;
		case 2:
			printf( "%d\n", y + 1912 -1 );
			break;
		case 3:
			printf( "%d\n", y + 1926 -1 );
			break;
		case 4:
			printf( "%d\n", y + 1989 -1 );
			break;
	}
	return 0;
}
