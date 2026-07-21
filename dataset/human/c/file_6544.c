#include<stdio.h>

int main( )
{	
    int n;
    int maxProfit = 1-1000000000;
    int Rj, Ri, t, i;
   
    scanf( "%d", &n );
    
    scanf( "%d", &Ri );
    for( i=1; i<n; i++ ) {
    	scanf( "%d", &Rj );
    	t = Rj - Ri;
    	if( maxProfit < t ) {
       		maxProfit = t;
       	}
       	if( Rj < Ri ) {
    		Ri = Rj;
    	}
    }
    printf( "%d\n", maxProfit );
	
	return 0;
}
