#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 内部定数
#define D_MAX_SIZE		50										// 最大サイズ
#define D_MASS_BLACK	'#'										// 黒マス

// 内部変数
static int siH;													// 高さ
static int siW;													// 幅
static char sc2Mass[D_MAX_SIZE][D_MAX_SIZE + 5];				// マス

// 内部変数 - テスト用
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpT, *szpFpA;
#endif

// 黒マス判定
int
fChkMassBlack(
	int piRow					// <I> 行 0～
	, int piCol					// <I> 列 0～
)
{
	// 範囲チェック
	if (piRow < 0 || siH <= piRow) {
		return -1;
	}
	if (piCol < 0 || siW <= piCol) {
		return -1;
	}

	// 黒マス判定
	if (sc2Mass[piRow][piCol] == D_MASS_BLACK) {	// 黒マス
		return 0;
	}

	return -1;
}

// マス判定
int
fChkMass(
)
{
	int i, j, liRet;

	for (i = 0; i < siH; i++) {
		for (j = 0; j < siW; j++) {

			// 黒マス判定
			if (sc2Mass[i][j] != D_MASS_BLACK) {	// 黒マス以外
				continue;
			}

			// 右方向
			liRet = fChkMassBlack(i, j + 1);
			if (liRet == 0) {						// 黒マス
				continue;
			}

			// 左方向
			liRet = fChkMassBlack(i, j - 1);
			if (liRet == 0) {						// 黒マス
				continue;
			}

			// 上方向
			liRet = fChkMassBlack(i + 1, j);
			if (liRet == 0) {						// 黒マス
				continue;
			}

			// 下方向
			liRet = fChkMassBlack(i - 1, j);
			if (liRet == 0) {						// 黒マス
				continue;
			}

			// 黒マスなし
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
	int i, liRet;
	char lc1Buf[1024], lc1Out[1024];

	// テストファイルオープン
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", piTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#endif

	// 高さ・幅取得
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d%d", &siH, &siW);

	// マス取得
	for (i = 0; i < siH; i++) {
#ifdef D_TEST
		fgets(sc2Mass[i], sizeof(sc2Mass[i]), szpFpT);
#else
		fgets(sc2Mass[i], sizeof(sc2Mass[i]), stdin);
#endif
	}

	// マス判定
	liRet = fChkMass();

	// 結果セット
	if (liRet == 0) {
		sprintf(lc1Out, "Yes\n");
	}
	else {
		sprintf(lc1Out, "No\n");
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
