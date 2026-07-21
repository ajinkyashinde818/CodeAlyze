#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 内部定数
#define D_ARRAY_MAX		100000									// 最大配列数
#define D_BIT_MAX		35										// 最大ビット数

// 内部構造体 - 値情報
typedef struct Val {
	char mc1Bit[D_BIT_MAX];										// 値
	int miVal;													// 価値
} Val;

// 内部変数
static FILE *szpFpI;											// 入力
static Val sz1Val[D_ARRAY_MAX];									// 配列
static int siACnt;												// 配列数
static char sc1K[D_BIT_MAX];									// K

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

// 最大値 - 取得
long long
fGetMaxL(
	long long plVal1			// <I> 値１
	, long long plVal2			// <I> 値２
)
{
	if (plVal1 > plVal2) {
		return plVal1;
	}
	else {
		return plVal2;
	}
}

// ビット化
int
fIntToBit(
	int piVal					// <I> 値
	, char *pcpBit				// <O> ビット
)
{
	int i;

	for (i = 0; i < D_BIT_MAX; i++) {
		pcpBit[i] = piVal % 2;
		piVal /= 2;
	}

	return 0;
}

// 価値合計 - 取得
long long
fGetVSum(
	char *pcpK					// <I> K
)
{
	int i, j;

	long long llVSum = 0;
	for (i = 0; i < siACnt; i++) {
		for (j = 0; j < D_BIT_MAX; j++) {
			if (sz1Val[i].mc1Bit[j] > pcpK[j]) {
				break;
			}
		}
		if (j == D_BIT_MAX) {
			llVSum += sz1Val[i].miVal;
		}
	}

	return llVSum;
}

// 実行メイン
int
fMain(
)
{
	int i, j;
	char lc1Buf[1024];

	// 配列数・K - 取得
	int liK;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &siACnt, &liK);
	fIntToBit(liK, sc1K);

	// 配列 - 取得
	for (i = 0; i < siACnt; i++) {
		int liVal;
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d%d", &liVal, &sz1Val[i].miVal);
		fIntToBit(liVal, sz1Val[i].mc1Bit);
	}

	// 最大値 - 取得
	long long llMax = fGetVSum(sc1K);
	for (i = D_BIT_MAX - 1; i >= 0; i--) {
		if (sc1K[i] == 0) {
			continue;
		}

		// 下位 ALL ON
		char lc1K[D_BIT_MAX];
		memcpy(lc1K, sc1K, sizeof(lc1K));
		lc1K[i] = 0;
		for (j = 0; j < i; j++) {
			lc1K[j] = 1;
		}

		// 価値合計 - 取得
		long long llVSum = fGetVSum(lc1K);
		llMax = fGetMaxL(llMax, llVSum);
	}

	// 出力
	sprintf(lc1Buf, "%lld\n", llMax);
	fOutLine(lc1Buf);

	return 0;
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
