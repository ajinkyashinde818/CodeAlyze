#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 内部定数
#define D_LOG_MAX		200000									// 最大丸太数

// 内部変数
static FILE *szpFpI;											// 入力
static int si1Log[D_LOG_MAX];									// 丸太
static int siLCnt;												// 丸太数

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
int
fGetMaxI(
	int piVal1					// <I> 値１
	, int piVal2				// <I> 値２
)
{
	if (piVal1 > piVal2) {
		return piVal1;
	}
	else {
		return piVal2;
	}
}

// カット回数 - 取得
long long
fGetCCnt(
	int piLen					// <I> 丸太長さ
)
{
	int i;

	long long llCCnt = 0;
	for (i = 0; i < siLCnt; i++) {
		llCCnt += si1Log[i] / piLen;
		if (si1Log[i] % piLen == 0) {
			llCCnt--;
		}
	}

	return llCCnt;
}

// 実行メイン
int
fMain(
)
{
	int i;
	char lc1Buf[1024];

	// 丸太数・最大カット回数 - 取得
	long long llMCnt;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%lld", &siLCnt, &llMCnt);

	// 丸太 - 取得
	int liMax = 0;
	for (i = 0; i < siLCnt; i++) {
		fscanf(szpFpI, "%d", &si1Log[i]);
		liMax = fGetMaxI(liMax, si1Log[i]);
	}
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);

	// 範囲を絞る
	int liMin = 1;
	int liLen = liMax;
	while (liMin <= liMax) {
		int liAvg = (liMin + liMax) / 2;

		// カット回数 - 取得
		long long llCCnt = fGetCCnt(liAvg);
		if (llCCnt > llMCnt) {
			liMin = liAvg + 1;
		}
		else {
			liMax = liAvg - 1;
			liLen = liAvg;
		}
	}

	return liLen;
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
	if (liRet == 0) {
		sprintf(lc1Buf, "Yes\n");
	}
	else {
		sprintf(lc1Buf, "No\n");
	}
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
