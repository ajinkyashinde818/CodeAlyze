#include<stdio.h>
#include<stdlib.h>



int point[ 100 ] ;



int desc( const void* a ,const void* b )
{
	return *( int* )b - *( int* )a ;
}



int main()
{
	int cnt = 0 ;
	int ans ;


	int i ,j ,k ;

	int n ;
	scanf( "%d" ,&n ) ;


	for( i = 0 ; i < n ; ++i )
	{
		scanf( "%d" ,&point[ i ] ) ;
	}


	qsort( point ,100 ,sizeof( int ) ,desc ) ;


	ans = n ;


	for( i = 0 ; i < n ; ++i )
	{
		if( cnt >= ans )
		{
			break ;
		}


		else if( point[ i ] >= ans )
		{
			++cnt ;
		}


		else
		{
			--i ;

			--ans ;
		}
	}


	printf( "%d\n" ,ans ) ;



	return 0 ;
}
