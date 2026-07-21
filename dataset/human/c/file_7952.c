#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 内部定数
#define D_DAY_MAX		200005									// 最大日数

// 内部変数
static FILE *szpFpI;											// 入力
static char sc1Str[D_DAY_MAX];									// 文字列
static int siDCnt;												// 日数
static int siWCnt;												// 働く日数
static int siSp;												// 働かない間隔
static int si1Work[D_DAY_MAX];									// 働く日

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
	memset(si1Work, 0, sizeof(si1Work));

	// 条件 - 取得
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d%d", &siDCnt, &siWCnt, &siSp);
	fgets(sc1Str, sizeof(sc1Str), szpFpI);

	// 働く日 - セット - 前詰め
	int liWCnt = 0;
	for (i = 0; i < siDCnt; i++) {
		if (sc1Str[i] == 'o') {
			si1Work[i]++;
			liWCnt++;
			i += siSp;
		}
	}
	if (liWCnt > siWCnt) {
		return 0;
	}

	// 働く日 - セット - 後詰め
	for (i = siDCnt - 1; i >= 0; i--) {
		if (sc1Str[i] == 'o') {
			si1Work[i]++;
			i -= siSp;
		}
	}

	// 出力
	for (i = 0; i < siDCnt; i++) {
		if (si1Work[i] == 2) {
			sprintf(lc1Buf, "%d\n", i + 1);
			fOutLine(lc1Buf);
		}
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
