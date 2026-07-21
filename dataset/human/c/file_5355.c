#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 内部定数
#define D_ARG_MAX		15										// 最大アルゴリズム数
#define D_BOOK_MAX		15										// 最大本数

// 内部構造体 - アルゴリズム情報
typedef struct Arg {
	int mi1Val[D_ARG_MAX];										// 値
} Arg;

// 内部構造体 - 本情報
typedef struct Book {
	int miVal;													// 価格
	Arg mzArg;													// アルゴリズム
} Book;

// 内部変数
static FILE *szpFpI;											// 入力
static Book sz1Book[D_BOOK_MAX];								// 本
static int siBCnt;												// 本数
static int siACnt;												// アルゴリズム数
static int siNVal;												// 必要値

// 内部変数 - テスト用
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
	static int siTNo;
#endif

// １行出力
int
fOutLine(
	char *pcpLine				// <I> １行
)
{
	char lc1Buf[1024];

#ifdef D_TEST
	lc1Buf[0] = '\0';
	fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
	if (strcmp(lc1Buf, pcpLine)) {
		siRes = -1;
	}
#else
	printf("%s", pcpLine);
#endif

	return 0;
}

// 最小値 - 取得
int
fGetMinI(
	int piVal1					// <I> 値１
	, int piVal2				// <I> 値２
)
{
	if (piVal1 < piVal2) {
		return piVal1;
	}
	else {
		return piVal2;
	}
}

// 金額の最小値 - 取得
int
fGetMin(
	int piBNo					// <I> 本
	, Arg *pzpArg				// <I> アルゴリズム
	, int piSum					// <I> 価格合計
)
{
	int i;

	// 終了
	if (piBNo >= siBCnt) {

		// 必要値チェック
		for (i = 0; i < siACnt; i++) {
			if (pzpArg->mi1Val[i] < siNVal) {
				return INT_MAX;
			}
		}

		return piSum;
	}

	// 買わない
	Arg lzArg;
	memcpy(&lzArg, pzpArg, sizeof(lzArg));
	int liMin = fGetMin(piBNo + 1, &lzArg, piSum);

	// 買う
	for (i = 0; i < siACnt; i++) {
		lzArg.mi1Val[i] += sz1Book[piBNo].mzArg.mi1Val[i];
	}
	int liMin2 = fGetMin(piBNo + 1, &lzArg, piSum + sz1Book[piBNo].miVal);
	liMin = fGetMinI(liMin, liMin2);

	return liMin;
}

// 実行メイン
int
fMain(
)
{
	int i, j;
	char lc1Buf[1024];

	// 本数・アルゴリズム数・必要値 - 取得
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d%d", &siBCnt, &siACnt, &siNVal);

	// 本 - 取得
	for (i = 0; i < siBCnt; i++) {
		fscanf(szpFpI, "%d", &sz1Book[i].miVal);
		for (j = 0; j < siACnt; j++) {
			fscanf(szpFpI, "%d", &sz1Book[i].mzArg.mi1Val[j]);
		}
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	}

	// 金額の最小値 - 取得
	Arg lzArg;
	memset(&lzArg, 0, sizeof(lzArg));
	int liMin = fGetMin(0, &lzArg, 0);
	if (liMin == INT_MAX) {
		return -1;
	}

	return liMin;
}

// １回実行
int
fOne(
)
{
	int liRet;
	char lc1Buf[1024];

	// 入力 - セット
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", siTNo);
	szpFpI = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", siTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#else
	szpFpI = stdin;
#endif

	// 実行メイン
	liRet = fMain();

	// 出力
	sprintf(lc1Buf, "%d\n", liRet);
	fOutLine(lc1Buf);

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
		printf("OK %d\n", siTNo);
	}
	else {
		printf("NG %d\n", siTNo);
	}
#endif

	return 0;
}

// プログラム開始
int
main()
{

#ifdef D_TEST
	int i;
	for (i = D_TEST_SNO; i <= D_TEST_ENO; i++) {
		siTNo = i;
		fOne();
	}
#else
	fOne();
#endif

	return 0;
}
