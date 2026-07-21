/*********************************
*include
*********************************/
#include <stdio.h>

/*********************************
*define
*********************************/
int input_ary[ 10000 ];

/*********************************
*function
*********************************/
int main( void )
{
	int input;
	int case_count;
	int loop;
char ch;
	case_count = 0;
	input = 0;

	while( 1 ) {
		scanf( "%d", &input );
		if ( 0 == input ) {
			break;
		}
		input_ary[ case_count ] = input;
		case_count++;
	}
	
	for( loop = 0; loop < case_count; loop++ ) {
		printf( "Case %d: %d\n", loop + 1, input_ary[ loop ] );
	}
	while( ( ch = getchar() ) != EOF );
	return ( 0 );
}
