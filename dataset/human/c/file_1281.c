#include <stdio.h>
#define N 8

int main( void ) {
  int i, j;
  int d[ N ] = { 1, 2, 1, 2, 1, 4, 1, 4 };
  int num[ N ];
  int dt[ N ][ N ];
  int p[ N ];

  /* 配列から値へ */
  for( i = 0; i < N; i++ ) {
    num[ i ] = 0;
    for( j = 0; j < N; j++ ) {
      num[ i ] *= 10;
      num[ i ] += d[ ( i+j ) % N ];
    }
  }

  /* 値のソート */
  for( i = 0; i < N-1; i++ ) {
    int w = num[ i+1 ];
    for( j = i+1; j > 0 && num[ j-1 ] > w; j-- )
      num[ j ] = num[ j-1 ];
    num[ j ] = w;
  }

  /* 値から配列へ */
  for( i = 0; i < N; i++ ) {
    for( j = N-1; j >= 0; j-- ) {
      dt[ i ][ j ] = num[ i ] % 10;
      num[ i ] /= 10;
    }
  }

  /* 実際の処理 */
  while( scanf( "%d%d%d%d%d%d%d%d",
        &p[ 0 ], &p[ 1 ], &p[ 2 ], &p[ 3 ],
        &p[ 4 ], &p[ 5 ], &p[ 6 ], &p[ 7 ] ) == 8 ) {
    int dsum, msumind, msum; // 合計値，合計最大値インデックス

    /* 0番目を最小として始める */
    dsum = 0;
    for( j = 0; j < N; j++ )
      if( p[ j ] > dt[ 0 ][ j ] )
        dsum += p[ j ] - dt[ 0 ][ j ];
    msum = dsum;
    msumind = 0;

    /* 1番目以降を見ていく */
    for( i = 1; i < N; i++ ) {
      dsum = 0;
      for( j = 0; j < N; j++ )
        if( p[ j ] > dt[ i ][ j ] )
          dsum += p[ j ] - dt[ i ][ j ];

      if( msum > dsum ) {
        msumind = i;
        msum = dsum;
      }
    }

    /* 出力 */
    for( j = 0; j < N; j++ ) {
      printf( "%d", dt[ msumind ][ j ] );
      if( j < N-1 )
        printf( " " );
    }
    printf( "\n" );
  }

  return( 0 );
}
