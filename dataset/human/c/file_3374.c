#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 内部定数
#define D_STR_MAX		100000									// 最大文字数
#define D_CHK_CNT		4										// チェック文字列数

// 内部変数
static char sc1Str[D_STR_MAX + 5];								// 文字列
static char sc2Chk[D_CHK_CNT][16];								// チェック文字列
static int si1Chk[D_CHK_CNT];									// チェック文字列長

// 内部変数 - テスト用
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// 改行カット
int
fCutCfLf(
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

	return 0;
}

// 作成可能かチェック
int
fChk(
)
{
	int i;

	// 現在位置
	int liNNo = strlen(sc1Str);

	while (liNNo > 0) {
		 
		// チェック文字列と比較
		int liRet = -1;
		for (i = 0; i < D_CHK_CNT; i++) {

			// 比較位置
			int liCNo = liNNo - si1Chk[i];
			if (liCNo < 0) {
				continue;
			}

			// 比較
			if (memcmp(&sc1Str[liCNo], sc2Chk[i], si1Chk[i])) {		// 不一致
				continue;
			}

			// 一致
			liRet = 0;
			liNNo = liCNo;											// 現在位置更新
			break;
		}
		if (liRet != 0) {
			return -1;
		}
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

	// テストファイルオープン
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#endif

	// 文字列取得
#ifdef D_TEST
	fgets(sc1Str, sizeof(sc1Str), szpFpT);
#else
	fgets(sc1Str, sizeof(sc1Str), stdin);
#endif

	// 改行カット
	fCutCfLf(sc1Str);

	// チェック文字列
	strcpy(sc2Chk[0], "dream");
	strcpy(sc2Chk[1], "dreamer");
	strcpy(sc2Chk[2], "erase");
	strcpy(sc2Chk[3], "eraser");

	// チェック文字列長
	for (i = 0; i < D_CHK_CNT; i++) {
		si1Chk[i] = strlen(sc2Chk[i]);
	}

	// 作成可能かチェック
	int liRet = fChk();

	// 結果セット
	if (liRet == 0) {
		sprintf(lc1Out, "YES\n");
	}
	else {
		sprintf(lc1Out, "NO\n");
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
