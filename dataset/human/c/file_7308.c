#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 内部定数
#define D_SIZE_MAX		305										// 最大サイズ

// 内部変数
static FILE *szpFpI;											// 入力
static int siW, siH;											// 幅・高さ
static char sc2Mass[D_SIZE_MAX][D_SIZE_MAX];					// マス
static int si1SCnt[D_SIZE_MAX];									// イチゴ数
static int si2No[D_SIZE_MAX][D_SIZE_MAX];						// 番号

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

// 実行メイン
int
fMain(
)
{
	int i, j, k;
	char lc1Buf[2048], lc1Buf2[128];

	// 幅・高さ - 取得
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &siH, &siW);

	// マス - 取得
	for (i = 0; i < siH; i++) {
		fgets(sc2Mass[i], sizeof(sc2Mass[0]), szpFpI);
		sc2Mass[i][siW] = '#';

		// イチゴ数 - セット
		for (j = 0; j < siW; j++) {
			if (sc2Mass[i][j] == '#') {
				si1SCnt[i]++;
			}
		}
	}
	si1SCnt[siH] = 1;

	// 番号 - セット
	int liNo = 1;
	int liHSNo = 0;
	while (liHSNo < siH) {
		int liHENo, liHMNo;

		// 範囲 - 行 - 取得
		int liSCnt = 0;
		for (liHENo = liHSNo; ; liHENo++) {
			if (si1SCnt[liHENo] > 0) {
				if (liSCnt == 0) {
					liSCnt++;
					liHMNo = liHENo;
				}
				else {
					liHENo--;
					break;
				}
			}
		}

		// イチゴ数でループ
		int liWSNo = 0;
		for (i = 0; i < si1SCnt[liHMNo]; i++) {
			int liWENo;

			// 範囲 - 列 - 取得
			liSCnt = 0;
			for (liWENo = liWSNo; ; liWENo++) {
				if (sc2Mass[liHMNo][liWENo] == '#') {
					if (liSCnt == 0) {
						liSCnt++;
					}
					else {
						liWENo--;
						break;
					}
				}
			}

			// 番号 - セット
			for (j = liHSNo; j <= liHENo; j++) {
				for (k = liWSNo; k <= liWENo; k++) {
					si2No[j][k] = liNo;
				}
			}
			liNo++;

			// 次の開始列
			liWSNo = liWENo + 1;
		}

		// 次の開始行
		liHSNo = liHENo + 1;
	}

	// 出力
	for (i = 0; i < siH; i++) {
		sprintf(lc1Buf, "%d", si2No[i][0]);
		for (j = 1; j < siW; j++) {
			sprintf(lc1Buf2, " %d", si2No[i][j]);
			strcat(lc1Buf, lc1Buf2);
		}
		strcat(lc1Buf, "\n");
		fOutLine(lc1Buf);
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

	// データ - 初期化
	memset(si1SCnt, 0, sizeof(si1SCnt));						// イチゴ数

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
