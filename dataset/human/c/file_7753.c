#include<stdio.h>



int main()
{
	int times ;

	int rock ,person ;


	scanf( "%d" ,&times ) ;


	while( times-- )
	{
		scanf( "%d %d" ,&rock ,&person ) ;


		rock = rock % person ;


		printf( "%d\n" ,rock > 0 ? rock : person ) ;
	}



	return 0 ;
}
