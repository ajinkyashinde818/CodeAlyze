#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 内部定数
#define D_TOWN_MAX		200000									// 最大町数

// 内部変数
static FILE *szpFpI;											// 入力
static int siTCnt;												// 町数
static long long slMCnt;										// 移動回数
static int si1To[D_TOWN_MAX];									// 行き先
static int si1MCnt[D_TOWN_MAX];									// 移動回数[町]

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

// 実行メイン
int
fMain(
)
{
	int i;
	char lc1Buf[1024];

	// データ - 初期化
	memset(si1MCnt, -1, sizeof(si1MCnt));

	// 町数・移動回数 - 取得
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%lld", &siTCnt, &slMCnt);

	// 行き先 - 取得
	for (i = 0; i < siTCnt; i++) {
		fscanf(szpFpI, "%d", &si1To[i]);
		si1To[i]--;
	}
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);

	// 移動回数[町] - セット
	int liTNo = 0;
	si1MCnt[liTNo] = 0;
	int liMCnt = 0;
	while (slMCnt > 0) {

		// 移動先
		liMCnt++;
		slMCnt--;
		int liTNo2 = si1To[liTNo];

		// 新規
		if (si1MCnt[liTNo2] < 0) {
			si1MCnt[liTNo2] = liMCnt;
		}

		// ２回目
		else {

			// 周回
			int liLen = liMCnt - si1MCnt[liTNo2];
			long long llRCnt = slMCnt / (long long)liLen;
			slMCnt -= llRCnt * (long long)liLen;
		}

		// 次へ
		liTNo = liTNo2;
	}

	return liTNo + 1;
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
