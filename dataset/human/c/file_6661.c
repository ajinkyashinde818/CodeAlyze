#include <stdio.h>

// 入力制約
#define NUM_MIN ( ( int ) 2 )
#define NUM_MAX ( ( int ) 200000 )
#define PRICE_MIN ( ( int ) 1 )
#define PRICE_MAX ( ( int ) 1000000000 )

// 制約判定結果
typedef enum
{
	kSuccess,
	kError
}Result;

// プロトタイプ宣言
Result checkNumRange( int num, int min, int max );
int calcMaxPrice( int num, int* pPrice );

//****************************************************/
// @brief  メイン関数
// @param  無し
// @return 正常終了なら0、異常終了なら-1を返す
//****************************************************/
int main( void )
{
	int i;
	int num;
	int price[NUM_MAX];

	// 価格数の入力判定
	scanf( "%d\n", &num );
	if( checkNumRange( num, NUM_MIN, NUM_MAX ) == kError )
	{
		return -1;
	}

	// 価格の入力判定
	for( i = 0; i < num; i++ )
	{
		scanf( "%d\n", &price[i] );
		if( checkNumRange( price[i], PRICE_MIN, PRICE_MAX ) == kError )
		{
			return -1;
		}
	}

	// 計算した最大利益を出力
	printf( "%d\n", calcMaxPrice( num, &price[0] ) );

	return 0;
}

//****************************************************/
// @brief  入力値の制約判定
// @param  num : 判定対象の入力値
//         min : 最小値
//         max : 最大値
// @return 制約内ならkSuccess、制約外ならkErrorを返す
//****************************************************/
Result checkNumRange( int num, int min, int max )
{
	return ( ( num >= min ) && ( num <= max ) ) ? kSuccess : kError;
}

//****************************************************/
// @brief  最大利益の計算
// @param  num    : 計算対象数値の個数
// @param  pPrice : 計算対象を格納した配列先頭へのポインタ
// @return 最大利益
//****************************************************/
int calcMaxPrice( int num, int* pPrice )
{
	int i;
	int maxPrice = pPrice[1] - pPrice[0];
	int minPrice = pPrice[0];

	// 最大利益と最少利益を計算
	for( i = 1; i <= num - 1; i++ )
	{
		maxPrice = ( maxPrice > ( pPrice[i] - minPrice ) ) ? maxPrice : ( pPrice[i] - minPrice );
		minPrice = ( minPrice < pPrice[i] ) ? minPrice : pPrice[i];
	}

	// 最大利益を返す
	return maxPrice;
}
