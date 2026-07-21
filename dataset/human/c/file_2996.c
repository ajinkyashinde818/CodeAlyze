#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 内部定数
#define D_BOX_MAX		100005									// 最大箱数

// 内部変数
static FILE *szpFpI;											// 入力
static int si1SCnt[D_BOX_MAX];									// 石数
static int siBCnt;												// 箱数
static int si1MCnt[D_BOX_MAX];									// 最大値回数

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

// 最大値回数 - セット
int
fSetMCnt(
	int piBNo					// <I> 箱
	, int piMCnt				// <I> 最大値回数
)
{
	if (si1MCnt[piBNo] > piMCnt) {
		return -1;
	}
	si1MCnt[piBNo] = piMCnt;

	return 0;
}

// 実行メイン
int
fMain(
)
{
	int i, liRet;
	char lc1Buf[1024];

	// データ - 初期化
	memset(si1MCnt, 0, sizeof(si1MCnt));

	// 箱数 - 取得
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d", &siBCnt);
	if (siBCnt < 2) {
		return 0;
	}

	// 石数・石数合計 - 取得
	long long llSSum = 0;
	for (i = 0; i < siBCnt; i++) {
		fscanf(szpFpI, "%d", &si1SCnt[i]);
		llSSum += si1SCnt[i];
	}
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	si1SCnt[siBCnt] = si1SCnt[0];

	// １回の削除石数
	long long llDel = (long long)siBCnt * (long long)(siBCnt + 1) / 2;

	// 削除回数
	if (llSSum % llDel != 0) {
		return -1;
	}
	int liDCnt = (int)(llSSum / llDel);

	// 最大値回数 - セット
	for (i = 0; i < siBCnt; i++) {

		// 最大値回数 - 取得
		int liMCnt1 = 0;
		int liSCnt1 = si1SCnt[i];
		int liSCnt2 = si1SCnt[i + 1];
		if (liSCnt1 > liSCnt2) {
			liMCnt1 = (liSCnt1 - liSCnt2 - 1) / (siBCnt - 1) + 1;
			liSCnt1 -= siBCnt * liMCnt1;
			if (liSCnt1 < 0) {
				return -1;
			}
			liSCnt2 -= liMCnt1;
			if (liSCnt2 < 0) {
				return -1;
			}
		}
		int liDCnt2 = liMCnt1 + liSCnt2 - liSCnt1;
		if (liDCnt < liDCnt2) {
			return -1;
		}
		liDCnt2 = liDCnt - liDCnt2;
		if (liDCnt2 % siBCnt) {
			return -1;
		}
		int liMCnt2 = liDCnt2 / siBCnt;
		liMCnt1 += liMCnt2;

		// 最大値回数 - セット
		liRet = fSetMCnt(i, liMCnt1);
		if (liRet != 0) {
			return -1;
		}
		liRet = fSetMCnt(i + 1, liMCnt2);
		if (liRet != 0) {
			return -1;
		}
	}

	// 最大値回数 - 合計
	int liSum = 0;
	for (i = 0; i < siBCnt; i++) {
		liSum += si1MCnt[i];
	}
	if (liSum != liDCnt) {
		return -1;
	}

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

	// １行出力
	if (liRet == 0) {
		sprintf(lc1Buf, "YES\n");
	}
	else {
		sprintf(lc1Buf, "NO\n");
	}
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
