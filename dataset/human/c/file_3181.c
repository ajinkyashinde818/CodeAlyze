#include <stdio.h>

int int_sort( const void *a, const void *b ){
    return *(int *)b - *(int *)a;
}

int main(void){
    // 変数
    int result = 0;
    int subtract = 0;
    int max = 0, max_index = 0;
    int k, n;
    int i;
    int a[210000];
    int total[210000];

    // 入力
    scanf( "%d %d", &k, &n );
    for( i = 0; i < n ; i++ ){
        scanf( "%d", &a[ i ] );
    }

    // 演算
    qsort( (void * )a, n, sizeof( a[0] ), int_sort );

    // 区間毎の距離格納、最大値の要素番号を格納
    for( i = 0 ; i < (n-1) ; i++ ){
        total[ i ] = a[ i ] - a[ i + 1 ];
        if( max < a[ i ] - a[ i + 1 ] ){
            max = a[ i ] - a[ i + 1 ];
            max_index = i;
        }
    }

    // 座標０をまたいだ計算
    subtract = ( k - a[0] ) + a[ n - 1 ];

    // 距離の総和
    for( i = 0; i < ( n - 1 ); i++ ){
        result += total[ i ];
    }

    // 区間毎の最大値と、座標０をまたいだ距離を比較し、どちらが大きいか比較
    if( subtract < max ){
        // 区間毎の方が大きい場合
        result += subtract;
        result -= total[ max_index ];
    }

    // 出力
    printf( "%d\n", result );

    return 0;
}
