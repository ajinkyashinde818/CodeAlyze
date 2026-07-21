#include<stdio.h>


int main( void )
{
	int N ,LIST ;
	while( 1 )
	{
		scanf( "%d %d" ,&N ,&LIST ) ;

		if( N | LIST )
		{
			int ans[ 500 + 1 ] = { 0 } ;

			int fri[ 500 + 1 ][ 500 + 1 ] = { 0 } ;

			int cnt = 0 ;
			int a ,b ;

			int i ,j ,k ;
			for( i = 0 ; i < LIST ; ++i )
			{
				scanf( "%d %d" ,&a ,&b ) ;

				fri[ a ][ b ] = fri[ b ][ a ] = 1 ;
			}

			for( i = 2 ; i <= N ; ++i )
			{
				if( fri[ 1 ][ i ] == 1 )
				{
					++ans[ i ] ;

					cnt += ( ans[ i ] == 1 ) ;

					for( j = 2 ; j <= N ; ++j )
					{
						if( fri[ i ][ j ] == 1 )
						{
							++ans[ j ] ;

							cnt += ( ans[ j ] == 1 ) ;
						}
					}
				}
			}

			printf( "%d\n" ,cnt ) ;
		}

		else
		{
			return 0 ;
		}
	}
}
