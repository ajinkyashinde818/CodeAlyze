#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 内部定数
#define D_ARRAY_MAX		200000									// 最大配列数

// 内部変数
static int si1Array[D_ARRAY_MAX];								// 配列
static int siACnt;												// 配列数

// 内部変数 - テスト用
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// 実行メイン
int
fMain(
	int piTNo					// <I> テスト番号 1～
)
{
	int i;
	char lc1Buf[1024], lc1Out[1024];

	// テストファイルオープン
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#endif

	// 配列数取得
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d", &siACnt);

	// 配列取得・合計取得
	long long llSum1 = 0;
	for (i = 0; i < siACnt; i++) {
#ifdef D_TEST
		fscanf(szpFpT, "%d", &si1Array[i]);
#else
		fscanf(stdin, "%d", &si1Array[i]);
#endif
		llSum1 += (long long)si1Array[i];
	}
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif

	// 初期値
	llSum1 -= (long long)si1Array[siACnt - 1];
	long long llSum2 = si1Array[siACnt - 1];
	long long llMin = llabs(llSum1 - llSum2);

	// 全パターンチェック
	for (i = siACnt - 2; i > 0; i--) {
		llSum1 -= (long long)si1Array[i];
		llSum2 += (long long)si1Array[i];
		long long llVal = llabs(llSum1 - llSum2);
		if (llMin > llVal) {
			llMin = llVal;
		}
	}

	// 結果セット
	sprintf(lc1Out, "%lld\n", llMin);

	// 結果表示
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
	if (strcmp(lc1Buf, lc1Out)) {
		siRes = -1;
	}
#else
	printf("%s", lc1Out);
#endif

	// テストファイルクローズ
#ifdef D_TEST
	fclose(szpFpT);
	fclose(szpFpA);
#endif

	// テスト結果
#ifdef D_TEST
	if (siRes == 0) {
		printf("OK %d\n", piTNo);
	}
	else {
		printf("NG %d\n", piTNo);
	}
#endif

	return 0;
}

int
main()
{

#ifdef D_TEST
	int i;
	for (i = D_TEST_SNO; i <= D_TEST_ENO; i++) {
		fMain(i);
	}
#else
	fMain(0);
#endif

	return 0;
}
