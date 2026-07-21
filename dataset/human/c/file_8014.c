#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 内部定数
#define D_MOD			1000000007								// 除数(10の9乗+7)
#define D_FACT_MAX		1000000									// 最大階乗数

// 内部変数
static FILE *szpFpI;											// 入力
static int si1ModFact[D_FACT_MAX];								// 階乗リスト
static int si1ModFactR[D_FACT_MAX];								// 階乗リスト(逆元)

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
	fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
	if (strcmp(lc1Buf, pcpLine)) {
		siRes = -1;
	}
#else
	printf("%s", pcpLine);
#endif

	return 0;
}

// 値 - 入れ替え
int
fSwap(
	int *pipVal1				// <IO> 値１
	, int *pipVal2				// <IO> 値２
)
{
	int liWork = *pipVal1;
	*pipVal1 = *pipVal2;
	*pipVal2 = liWork;

	return 0;
}

// べき乗 - 取得
int
fGetModPower(
	int piBase					// <I> 基数
	, int piIdx					// <I> 指数
)
{
	// 平方リスト - 作成
	int li1Val[100];
	li1Val[0] = piBase;
	int liCnt = 1;
	int liIdx = 1;
	while (piIdx > liIdx) {
		li1Val[liCnt] = (int)((long long)li1Val[liCnt - 1] * (long long)li1Val[liCnt - 1] % D_MOD);
		liCnt++;
		liIdx += liIdx;
	}

	// べき乗 - 取得
	int liVal = 1;
	while (piIdx > 0) {
		if (piIdx >= liIdx) {
			piIdx -= liIdx;
			liVal = (int)((long long)liVal * (long long)li1Val[liCnt - 1] % D_MOD);
		}
		liCnt--;
		liIdx /= 2;
	}

	return liVal;
}

// 階乗リスト - 作成
int
fMakeModFact(
	int piMax					// <I> 最大値
)
{
	int i;

	si1ModFact[0] = 1;
	si1ModFact[1] = 1;
	for (i = 2; i <= piMax; i++) {
		si1ModFact[i] = (int)((long long)si1ModFact[i - 1] * (long long)i % D_MOD);
	}

	return 0;
}

// 階乗リスト(逆元) - 作成
int
fMakeModFactR(
	int piMax					// <I> 最大値
)
{
	int i;

	for (i = 0; i <= piMax; i++) {
		si1ModFactR[i] = fGetModPower(si1ModFact[i], D_MOD - 2);
	}

	return 0;
}

// nCk - 取得
int
fGetnCk(
	int piN						// <I> N
	, int piK					// <I> K
)
{
	if (piN < piK) {
		return 0;
	}
	if (piK < 0) {
		return 0;
	}
	int liCnt = (int)((long long)si1ModFact[piN] * (long long)si1ModFactR[piN - piK] % D_MOD);
	return (int)((long long)liCnt * (long long)si1ModFactR[piK] % D_MOD);
}

// 実行メイン
int
fMain(
)
{
	char lc1Buf[1024];

	// 目的位置 - 取得
	int liX, liY;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &liX, &liY);
	int liSum = liX + liY;

	// 移動可能かチェック
	if (liSum % 3 != 0) {
		return 0;
	}

	// 移動回数 - 取得
	int liMCnt = liSum / 3;
	int liVal = 2 * liX - liY;
	if (liVal % 3 != 0) {
		return 0;
	}
	int liXCnt = liVal / 3;
	if (liXCnt < 0 || liMCnt < liXCnt) {
		return 0;
	}

	// 階乗リスト - 作成
	fMakeModFact(liMCnt);
	fMakeModFactR(liMCnt);

	// nCk - 取得
	return fGetnCk(liMCnt, liXCnt);
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
