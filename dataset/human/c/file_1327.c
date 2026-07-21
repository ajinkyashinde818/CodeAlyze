#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 内部定数
#define D_SHIP_MAX		200000									// 最大定期便数

// 内部変数
static int si1Ship1[D_SHIP_MAX + 5];							// 定期便1
static int siS1Cnt;												// 定期便1数
static int si1ShipN[D_SHIP_MAX + 5];							// 定期便N
static int siSNCnt;												// 定期便N数

// 内部変数 - テスト用
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// ソート関数 - int昇順
int
fSortFnc(
	const void *pzpVal1			// <I> 値１
	, const void *pzpVal2		// <I> 値２
)
{
	int *lipVal1 = (int *)pzpVal1;
	int *lipVal2 = (int *)pzpVal2;

	// 昇順
	if (*lipVal1 >  *lipVal2) {
		return(1);
	}
	else if (*lipVal1 < *lipVal2) {
		return(-1);
	}

	return 0;
}

// 実行メイン
int
fMain(
	int piTNo					// <I> テスト番号 1～
)
{
	int i;
	char lc1Buf[1024], lc1Out[1024];

	// データ初期化
	siS1Cnt = 0;												// 定期便1数
	siSNCnt = 0;												// 定期便N数

	// テストファイルオープン
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#endif

	// 目的地・定期便数取得
	int liN, liSCnt;
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d%d", &liN, &liSCnt);

	// 定期便取得
	for (i = 0; i < liSCnt; i++) {
		int liFNo, liTNo;
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
		sscanf(lc1Buf, "%d%d", &liFNo, &liTNo);

		if (liFNo == 1) {
			si1Ship1[siS1Cnt] = liTNo;
			siS1Cnt++;
		}
		else if (liTNo == 1) {
			si1Ship1[siS1Cnt] = liFNo;
			siS1Cnt++;
		}
		else if (liFNo == liN) {
			si1ShipN[siSNCnt] = liTNo;
			siSNCnt++;
		}
		else if (liTNo == liN) {
			si1ShipN[siSNCnt] = liFNo;
			siSNCnt++;
		}
	}

	// 定期便ソート
	qsort(si1Ship1, siS1Cnt, sizeof(int), fSortFnc);
	qsort(si1ShipN, siSNCnt, sizeof(int), fSortFnc);

	// マッチング
	int liRet = -1;
	int liS1No = 0;
	int liSNNo = 0;
	while (1) {

		// 終了チェック
		if (liS1No >= siS1Cnt) {
			break;
		}
		if (liSNNo >= siSNCnt) {
			break;
		}

		// 比較
		if (si1Ship1[liS1No] < si1ShipN[liSNNo]) {
			liS1No++;
		}
		else if (si1Ship1[liS1No] == si1ShipN[liSNNo]) {	// 一致
			liRet = 0;
			break;
		}
		else {
			liSNNo++;
		}
	}

	// 結果セット
	if (liRet == 0) {
		sprintf(lc1Out, "POSSIBLE\n");
	}
	else {
		sprintf(lc1Out, "IMPOSSIBLE\n");
	}

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
