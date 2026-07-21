#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 内部定数
#define D_PRM_MAX		100										// 最大素数数

// 内部構造体 - 素数情報
typedef struct Prm {
	long long mlVal;											// 値
	int miCnt;													// 個数
} Prm;

// 内部変数
static FILE *szpFpI;											// 入力
static Prm sz1Prm[D_PRM_MAX];									// 素数
static int siPCnt;												// 素数数

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

// 素因数分解
int
fDivPrm(
	long long plVal				// <I> 対象値
)
{
	int i;

	// 初期化
	memset(sz1Prm, 0, sizeof(sz1Prm));
	siPCnt = 0;

	// 上限
	int liLimit = (int)sqrt((double)plVal);

	// 素因数分解
	for (i = 2; i <= liLimit; i++) {

		// 分解終了
		if (plVal == 1) {
			break;
		}

		// 分解
		while (plVal % (long long)i == 0) {
			plVal /= i;
			sz1Prm[siPCnt].miCnt++;
		}

		// 分解あり
		if (sz1Prm[siPCnt].miCnt > 0) {
			sz1Prm[siPCnt].mlVal = i;
			siPCnt++;
		}
	}

	// 上限を超える素数
	if (plVal != 1) {
		sz1Prm[siPCnt].miCnt = 1;
		sz1Prm[siPCnt].mlVal = plVal;
		siPCnt++;
	}

	return 0;
}

// 実行メイン
int
fMain(
)
{
	int i, j;
	char lc1Buf[1024];

	// データ - 初期化

	// 値 - 取得
	long long llVal;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%lld", &llVal);

	// 素因数分解
	fDivPrm(llVal);

	// 回数 - 取得
	int liCnt = 0;
	for (i = 0; i < siPCnt; i++) {
		for (j = 1; ; j++) {
			if (sz1Prm[i].miCnt < j) {
				break;
			}
			else {
				sz1Prm[i].miCnt -= j;
				liCnt++;
			}
		}
	}

	return liCnt;
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
