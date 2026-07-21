#include<stdio.h>


inline int max( int a ,int b )
{
	return a > b ? a : b ;
}

inline int min( int a ,int b )
{
	return a > b ? b : a ;
}


int main( void )
{
	int ans = 0 ;

	int sx ,sy ;

	int W ,H ,N ;
	scanf( "%d %d %d" ,&W ,&H ,&N ) ;

	scanf( "%d %d" ,&sx ,&sy ) ;

	int i ;
	for( i = 1 ; i < N ; ++i )
	{
		int gx ,gy ;
		scanf( "%d %d" ,&gx ,&gy ) ;

		if( ( gx < sx && gy < sy ) || ( gx > sx && gy > sy ) )
		{
			ans += max( max( sx ,gx ) - min( sx ,gx ) ,max( sy ,gy ) - min( sy ,gy ) ) ;
		}

		else
		{
			ans += ( max( gx ,sx ) - min( gx ,sx ) ) + ( max( gy ,sy ) - min( gy ,sy ) ) ;
		}

		sx = gx ; sy = gy ;
	}

	printf( "%d\n" ,ans ) ;


	return 0 ;
}
