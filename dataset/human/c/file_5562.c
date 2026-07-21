#include <stdio.h>

#define MAX 150000

void makePrime( int * prime, int * sum )
{
        int i = 0, num = 0, tmp = 0, j;
        for ( i = 0 ; i < MAX+1 ; i++ ) {
                prime[i] = 1;
                sum[i]   = 0;
        }

        prime[0] = 0;
        prime[1] = 0;

        for ( i = 2 ; i < MAX+1 ; i++ ) {
                if ( prime[i] == 1 )
                {
                        num++;
                        for ( j = i + i ; j < MAX+1 ; j = i + j ) {
                                prime[j] = 0;
                        }
                        sum[num] = sum[num-1] + i;
                }
        }
}

int main()
{
        int prime[MAX] = {};
        int sum[MAX] = {};
        int num;

        makePrime( prime, sum );
        while( 1 ) {
                scanf( "%d", &num );
                if ( num == 0 ) break;
                printf( "%d\n", sum[num] );
                num = 0;
        }
        return 0;
}
