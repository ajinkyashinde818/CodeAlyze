#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 内部定数
#define D_CHAR_MAX		1000005									// 最大文字数

// 内部変数
static FILE *szpFpI;											// 入力
static char sc1Str[D_CHAR_MAX];									// 文字列
static int siCCnt;												// 文字数
static int si2Cnt[D_CHAR_MAX][2];								// 枚数

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

// 改行カット
// 戻り値：文字数
int
fCutCrLf(
	char *pcpStr				// <I> 文字列
)
{
	int i;

	for (i = 0; pcpStr[i] != '\0'; i++) {
		if (pcpStr[i] == '\n') {
			pcpStr[i] = '\0';
			break;
		}
	}

	return i;
}

// 最小値 - 取得
int
fGetMin(
	int piVal1					// <I> 値１
	, int piVal2				// <I> 値２
)
{
	if (piVal1 < piVal2) {
		return piVal1;
	}
	else {
		return piVal2;
	}
}

// 実行メイン
int
fMain(
)
{
	int i;

	// 文字列 - 取得
	sc1Str[0] = '0';
	fgets(&sc1Str[1], sizeof(sc1Str) - 1, szpFpI);
	siCCnt = fCutCrLf(sc1Str);

	// 数値化
	for (i = 0; i < siCCnt; i++) {
		sc1Str[i] -= '0';
	}

	// 枚数 - 初期化
	for (i = 0; i < siCCnt; i++) {
		si2Cnt[i][0] = INT_MAX;
		si2Cnt[i][1] = INT_MAX;
	}
	si2Cnt[siCCnt][0] = 0;
	si2Cnt[siCCnt][1] = 1;

	// 枚数 - セット
	for (i = siCCnt - 1; i >= 0; i--) {

		// 釣りなし + 釣りなし
		si2Cnt[i][0] = fGetMin(si2Cnt[i][0], si2Cnt[i + 1][0] + sc1Str[i]);

		// 釣りあり + 釣りなし
		si2Cnt[i][0] = fGetMin(si2Cnt[i][0], si2Cnt[i + 1][1] + sc1Str[i] + 1);

		// 釣りなし + 釣りあり
		si2Cnt[i][1] = fGetMin(si2Cnt[i][1], si2Cnt[i + 1][0] + 10 - sc1Str[i]);

		// 釣りあり + 釣りあり
		si2Cnt[i][1] = fGetMin(si2Cnt[i][1], si2Cnt[i + 1][1] + 10 - sc1Str[i] - 1);
	}

	return si2Cnt[0][0];
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
