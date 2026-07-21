#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 内部定数
#define D_ARRAY_MAX		100000									// 最大配列数
#define D_VAL_MAX		1000000000								// 最大値

// 内部変数
static FILE *szpFpI;											// 入力
static char sc1Out[D_ARRAY_MAX * 20];							// 出力内容
static char *scpOut;											// 出力位置

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

// 出力内容 - 追加
int
fOutAdd(
	int piVal					// <I> 値
)
{
	char lc1Buf[1024];
	sprintf(lc1Buf, "%d ", piVal);
	int liLen = strlen(lc1Buf);
	memcpy(scpOut, lc1Buf, liLen);
	scpOut += liLen;

	return 0;
}

// 実行メイン
int
fMain(
)
{
	int i;
	char lc1Buf[1024];

	// 条件 - 取得
	int liN, liK, liS;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d%d", &liN, &liK, &liS);

	// S を K 個追加
	for (i = 0; i < liK; i++) {
		fOutAdd(liS);
	}

	// !S を (N-K) 個追加
	int liVal;
	if (liS < D_VAL_MAX) {
		liVal = D_VAL_MAX;
	}
	else {
		liVal = 1;
	}
	for (i = 0; i < liN - liK; i++) {
		fOutAdd(liVal);
	}

	// 出力
	*scpOut = '\0';
	scpOut--;
	*scpOut = '\n';
	fOutLine(sc1Out);

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
	scpOut = sc1Out;											// 出力位置

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
