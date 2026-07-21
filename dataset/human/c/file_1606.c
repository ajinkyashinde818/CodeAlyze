#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 内部定数
#define D_STR_MAX		100000									// 最大文字列数

// 内部変数
static FILE *szpFpI;											// 入力
static char sc1Str[D_STR_MAX + 5];								// 文字列
static int siSLen;												// 文字列数

// 内部変数 - テスト用
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

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

// 操作回数 - 取得
int
fGetCnt(
)
{
	// 開始・終了位置
	int liLNo = 0;
	int liRNo = siSLen - 1;

	// 両端から比較
	int liCnt = 0;
	while (liLNo < liRNo) {
		if (sc1Str[liLNo] == sc1Str[liRNo]) {		// 同一文字
			liLNo++;
			liRNo--;
		}
		else if (sc1Str[liLNo] == 'x') {			// 左側
			liLNo++;
			liCnt++;
		}
		else if (sc1Str[liRNo] == 'x') {			// 右側
			liRNo--;
			liCnt++;
		}
		else {										// 不可
			return -1;
		}
	}

	return liCnt;
}

// 実行メイン
int
fMain(
	int piTNo					// <I> テスト番号 1～
)
{
	char lc1Buf[1024], lc1Out[1024];

	// 入力 - セット
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpI = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#else
	szpFpI = stdin;
#endif

	// 文字列 - 取得
	fgets(sc1Str, sizeof(sc1Str), szpFpI);

	// 文字列数 - 取得
	siSLen = fCutCrLf(sc1Str);

	// 操作回数 - 取得
	int liCnt = fGetCnt();

	// 結果 - セット
	sprintf(lc1Out, "%d\n", liCnt);

	// 結果 - 表示
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
	if (strcmp(lc1Buf, lc1Out)) {
		siRes = -1;
	}
#else
	printf("%s", lc1Out);
#endif

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
