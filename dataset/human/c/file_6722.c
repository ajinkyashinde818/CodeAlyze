#include<stdio.h>



int main()
{
	int N ,M ;
	while( 1 )
	{
		int ans =  0 ;

		int I[ 500 + 1 ] = { 0 } ;
		char friends[ 500 + 1 ][ 500 + 1 ] = { 0 } ;

		scanf( "%d %d" ,&N ,&M ) ;

		if( N | M )
		{
			int i ,j ;
			for( i = 0 ; i < M ; ++i )
			{
				int a ,b ;
				scanf( "%d %d" ,&a ,&b ) ;

				friends[ a ][ b ] = friends[ b ][ a ] = 1 ;
			}

			for( i = 2 ; i <= N ; ++i )
			{
				if( friends[ 1 ][ i ] == 1 )
				{
					++I[ i ] ;

					ans += I[ i ] < 2 ? I[ i ] : 0 ;

					for( j = 2 ; j <= N ; ++j )
					{
						if( friends[ i ][ j ] == 1 )
						{
							++I[ j ] ;

							ans += I[ j ] < 2 ? I[ j ] : 0 ;
						}
					}
				}
			}

			printf( "%d\n" ,ans ) ;
		}

		else
		{
			return 0 ;
		}
	}
}
