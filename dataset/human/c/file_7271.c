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
#define D_SIZE_MAX		85										// 最大サイズ
#define D_RNG_MAX		26000									// 最大範囲
#define D_RNG_AVG		D_RNG_MAX / 2							// 範囲中間値

// 内部変数
static FILE *szpFpI;											// 入力
static int siW, siH;											// 幅・高さ
static int si2DF[D_SIZE_MAX][D_SIZE_MAX];						// 数字差
static char sc3Exist[D_SIZE_MAX][D_SIZE_MAX][D_RNG_MAX];		// 存在フラグ

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
	char lc1Buf[1024];

	// データ - 初期化
	memset(sc3Exist, D_OFF, sizeof(sc3Exist));

	// 幅・高さ - 取得
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &siH, &siW);

	// 数字差 - 取得
	for (i = 0; i < siH; i++) {
		for (j = 0; j < siW; j++) {
			fscanf(szpFpI, "%d", &si2DF[i][j]);
		}
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	}
	for (i = 0; i < siH; i++) {
		for (j = 0; j < siW; j++) {
			int liVal;
			fscanf(szpFpI, "%d", &liVal);
			si2DF[i][j] -= liVal;
		}
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	}

	// 存在フラグ - 初期値
	sc3Exist[0][0][D_RNG_AVG + si2DF[0][0]] = D_ON;
	sc3Exist[0][0][D_RNG_AVG - si2DF[0][0]] = D_ON;

	// 存在フラグ - セット
	for (i = 0; i < siH; i++) {
		for (j = 0; j < siW; j++) {
			for (k = 0; k < D_RNG_MAX; k++) {
				if (sc3Exist[i][j][k] != D_ON) {
					continue;
				}

				// 右へ
				sc3Exist[i][j + 1][k + si2DF[i][j + 1]] = D_ON;
				sc3Exist[i][j + 1][k - si2DF[i][j + 1]] = D_ON;

				// 下へ
				sc3Exist[i + 1][j][k + si2DF[i + 1][j]] = D_ON;
				sc3Exist[i + 1][j][k - si2DF[i + 1][j]] = D_ON;
			}
		}
	}

	// 最小値 - 取得
	int liMin = INT_MAX;
	for (i = 0; i < D_RNG_MAX; i++) {
		if (sc3Exist[siH - 1][siW - 1][i] != D_ON) {
			continue;
		}

		// 最小値 - 更新
		int liVal = abs(D_RNG_AVG - i);
		if (liMin > liVal) {
			liMin = liVal;
		}
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
