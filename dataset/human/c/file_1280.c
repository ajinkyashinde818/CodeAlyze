#include <stdio.h>
#include <math.h>

int number( int c[8], int parm )
{
        int sum = 0;
        for ( int i = 0 ; i < 8 ; i++ ) {
                // printf( "%d\n", c[(i+parm)%8] );
                sum += c[(i+parm)%8] * ( int ) pow( 10.0, 7.0 - (double) i );
        }
        return sum;
}

int main()
{
        int p[8];
        int c[8] = { 4, 1, 4, 1, 2, 1, 2, 1 };
        int rest[8];
        int cnt, minval, restnum, i, minnum;

        while ( scanf( "%d %d %d %d %d %d %d %d",
                                &p[0], &p[1], &p[2], &p[3], &p[4], &p[5], &p[6], &p[7] ) != EOF ) {

                cnt = 0;
                minnum = 70000;
                minval = 0;

                /* @hF,0LCV$r$:$i$7$J$,$iBT$A?M?t$,:G>.$N>l9g$r7W;;$9$k*/
                while ( cnt < 8 ) {
                        restnum = 0;

                        /* */
                        for ( i = 0 ; i < 8 ; i++ ) {
                                rest[i] = p[i] - c[(i+cnt)%8];
                                if ( rest[i] < 0 ) {
                                        rest[i] = 0;
                                }
                                restnum += rest[i];
                        }

                        if ( restnum < minnum ) {
                                minnum = restnum;
                                minval = cnt;
                        } else if ( restnum == minnum ) {
                                // printf( "%7d, %7d\n", number( c, minval ), number( c, cnt ) );
                                if ( number( c, minval ) > number( c, cnt ) ) {
                                        minval = cnt;
                                }
                        }
                        cnt++;
                }

                for ( i = 0 ; i < 8 ; i++ ) {
                        if ( i == 7 ) {
                                printf( "%d\n", c[(i+minval)%8] );
                        } else {
                                printf( "%d ", c[(i+minval)%8] );
                        }
                }
        }

        return 0;
}
