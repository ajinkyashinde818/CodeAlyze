#include<stdio.h>


enum in
{
	M = 1867 ,
	T = 1911 ,
	S = 1925 ,
	H = 1988 ,

	e = 0 ,
	m ,
	t ,
	s ,
	h 
} ;



int when( int ,char* ,int ) ;



int main()
{
	int year ;

	char y_type ;


	int type ;
	scanf( "%d" ,&type ) ;


	if( type != e )
	{
		scanf( "%c" ,&y_type ) ;
	}

	scanf( "%d" ,&year ) ;


	if( type == e )
	{
		year -= when( year ,&y_type ,type ) ;

		printf( "%c" ,y_type ) ;
	}

	else
	{
		year += when( year ,&y_type ,type ) ;
	}


	printf( "%d\n" ,year ) ;


	return 0 ;
}




int when( int y ,char* c ,int type )
{
	if( type == e )
	{
		if( y > H )
		{
			y = H ;

			*c = 'H' ;
		}

		else if( y > S )
		{
			y = S ;

			*c = 'S' ;
		}

		else if( y > T )
		{
			y = T ;

			*c = 'T' ;
		}

		else
		{
			y = M ;

			*c = 'M' ;
		}
	}

	else
	{
		switch( type )
		{
			case h :
				y = H ;

				break ;


			case s :
				y = S ;

				break ;


			case t :
				y = T ;

				break ;


			case m :
				y = M ;

				break ;
		}
	}


	return y ;
}
