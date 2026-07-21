#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 内部定数
#define D_ON			1										// 汎用フラグ - ON
#define D_OFF			0										// 汎用フラグ - OFF
#define D_NUM_MAX		1000									// 最大数列数
#define D_SUM_MAX		D_NUM_MAX * (D_NUM_MAX + 1) / 2			// 最大和数
#define D_BIT_MAX		40										// 最大ビット数

// 内部構造体 - ビット情報
typedef struct Bit {
	char mc1Bit[D_BIT_MAX];										// ２進表記
} Bit;

// 内部変数
static FILE *szpFpI;											// 入力
static int si1Num[D_NUM_MAX];									// 数列
static int siNCnt;												// 数列数
static int siSCnt;												// 選択数
static long long sl2Sum[D_NUM_MAX][D_NUM_MAX];					// 数列の和[開始位置][終了位置]
static Bit sz1Bit[D_SUM_MAX];									// 数列の和(ビット)
static int siBCnt;												// 数列の和(ビット)数
static int siBSNo;												// ソート用ビット位置
static Bit szMax;												// 最大値

// 内部変数 - テスト用
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// 数列の和(ビット) - 追加
int
fAddBit(
	long long plVal				// <I> 値
)
{
	int i;
	long long llVal = 2;

	// 数列の和(ビット) - セット
	for (i = 0; ; i++) {
		if (plVal % 2 == 1) {
			sz1Bit[siBCnt].mc1Bit[i] = D_ON;
		}
		plVal /= 2;
		if (plVal < 1) {
			break;
		}
		llVal *= 2;
	}

	// 数列の和(ビット)数
	siBCnt++;

	return 0;
}

// ソート関数 - 降順
int
fSortFnc(
	const void *pzpVal1			// <I> 値１
	, const void *pzpVal2		// <I> 値２
)
{
	Bit *lzpVal1 = (Bit *)pzpVal1;
	Bit *lzpVal2 = (Bit *)pzpVal2;

	// 降順
	if (lzpVal1->mc1Bit[siBSNo] > lzpVal2->mc1Bit[siBSNo]) {
		return -1;
	}
	else if (lzpVal1->mc1Bit[siBSNo] < lzpVal2->mc1Bit[siBSNo]) {
		return 1;
	}

	return 0;
}

// 実行メイン
int
fMain(
	int piTNo					// <I> テスト番号 1～
)
{
	int i, j;
	char lc1Buf[1024], lc1Out[1024];

	// データ - 初期化
	memset(sz1Bit, 0, sizeof(sz1Bit));							// 数列の和(ビット)
	siBCnt = 0;													// 数列の和(ビット)数
	memset(&szMax, 0, sizeof(szMax));							// 最大値

	// 入力 - セット
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpI = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#else
	szpFpI = stdin;
#endif

	// 数列数・選択数 - 取得
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &siNCnt, &siSCnt);

	// 数列 - 取得
	for (i = 0; i < siNCnt; i++) {
		fscanf(szpFpI, "%d", &si1Num[i]);
	}
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);

	// 数列の和 - セット
	for (i = 0; i < siNCnt; i++) {
		sl2Sum[i][i] = si1Num[i];
		for (j = i + 1; j < siNCnt; j++) {
			sl2Sum[i][j] = sl2Sum[i][j - 1] + (long long)si1Num[j];
		}
	}

	// 数列の和(ビット) - セット
	for (i = 0; i < siNCnt; i++) {
		for (j = i; j < siNCnt; j++) {
			fAddBit(sl2Sum[i][j]);
		}
	}

	// 最大値 - セット
	for (i = D_BIT_MAX - 1; i >= 0; i--) {

		// ソート
		siBSNo = i;
		qsort(sz1Bit, siBCnt, sizeof(Bit), fSortFnc);

		// 選択数 - チェック
		if (sz1Bit[siSCnt - 1].mc1Bit[i] != D_ON) {		// なし
			continue;
		}

		// 最大値 - セット
		szMax.mc1Bit[i] = D_ON;

		// 範囲を絞る
		for (j = siSCnt; j < siBCnt; j++) {
			if (sz1Bit[j].mc1Bit[i] != D_ON) {				// なし
				siBCnt = j;
				break;
			}
		}
	}

	// 最大値 - 値化
	long long llSum = 0;
	long long llVal = 1;
	for (i = 0; i < D_BIT_MAX; i++) {
		if (szMax.mc1Bit[i] == D_ON) {
			llSum += llVal;
		}
		llVal *= 2;
	}

	// 結果 - セット
	sprintf(lc1Out, "%lld\n", llSum);

	// 結果 - 表示
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
	if (strcmp(lc1Buf, lc1Out)) {
		siRes = -1;
	}
#else
	printf("%s", lc1Out);
#endif

	// 残データ有無
#ifdef D_TEST
	lc1Buf[0] = '\0';
	fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
	if (strcmp(lc1Buf, "")) {
		siRes = -1;
	}
#endif

	// テストファイルクローズ
#ifdef D_TEST
	fclose(szpFpI);
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
