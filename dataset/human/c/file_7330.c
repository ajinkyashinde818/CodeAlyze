#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 内部定数
#define D_POINT_MAX		100000									// 最大地点数
#define D_LEN_MAX		100000000000							// 最大距離

// 内部変数
static FILE *szpFpI;											// 入力
static int siJCnt;												// 神社数
static int siTCnt;												// 寺数
static long long sl1JPos[D_POINT_MAX];							// 神社の位置
static long long sl1TPos[D_POINT_MAX];							// 寺の位置

// 内部変数 - テスト用
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
	static int siTNo;
#endif

// 検索＋前後
// 戻り値：[>=0]配列番号 [-1]なし
int
fBSrhPN(
	long long *plpArray			// <I> 検索する配列
	, int piCnt					// <I> 検索する配列数
	, long long plVal			// <I> 値
	, int *pipPNo				// <O> [>=0]１つ前の値の配列番号 [-1]なし
	, int *pipNNo				// <O> [>=0]１つ後の値の配列番号 [siACnt]なし
)
{
	// 初期範囲
	int liSNo = 0;
	int liENo = piCnt - 1;

	// 検索
	while (1) {

		// 中間位置
		int liMNo = (liSNo + liENo) / 2;

		// 一致チェック
		if (plVal == plpArray[liMNo]) {
			*pipPNo = liMNo;
			*pipNNo = liMNo;
			return 0;
		}

		// 範囲を絞る
		if (plVal < plpArray[liMNo]) {				// 左側へ
			if (liSNo < liMNo) {						// 範囲あり
				liENo = liMNo - 1;
			}
			else {										// 範囲なし
				*pipPNo = liMNo - 1;
				*pipNNo = liMNo;
				return 0;
			}
		}
		else {										// 右側へ
			if (liENo > liMNo) {						// 範囲あり
				liSNo = liMNo + 1;
			}
			else {										// 範囲なし
				*pipPNo = liMNo;
				*pipNNo = liMNo + 1;
				return 0;
			}
		}
	}

	return 0;
}

// 実行メイン
int
fMain(
)
{
	int i;
	char lc1Buf[1024], lc1Out[1024];

	// 神社数・寺数・問数 - 取得
	int liQCnt;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d%d", &siJCnt, &siTCnt, &liQCnt);

	// 神社 - 取得
	for (i = 0; i < siJCnt; i++) {
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%lld", &sl1JPos[i]);
	}

	// 寺 - 取得
	for (i = 0; i < siTCnt; i++) {
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%lld", &sl1TPos[i]);
	}

	// 問 - 取得
	for (i = 0; i < liQCnt; i++) {
		long long llPos;
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%lld", &llPos);

		// 現在位置の左右 - 取得 - 神社
		int liLNo, liRNo;
		long long llJLLen, llJRLen;
		fBSrhPN(sl1JPos, siJCnt, llPos, &liLNo, &liRNo);
		if (liLNo < 0) {
			llJLLen = D_LEN_MAX;
		}
		else {
			llJLLen = llPos - sl1JPos[liLNo];
		}
		if (liRNo >= siJCnt) {
			llJRLen = D_LEN_MAX;
		}
		else {
			llJRLen = sl1JPos[liRNo] - llPos;
		}

		// 現在位置の左右 - 取得 - 寺
		long long llTLLen, llTRLen;
		fBSrhPN(sl1TPos, siTCnt, llPos, &liLNo, &liRNo);
		if (liLNo < 0) {
			llTLLen = D_LEN_MAX;
		}
		else {
			llTLLen = llPos - sl1TPos[liLNo];
		}
		if (liRNo >= siTCnt) {
			llTRLen = D_LEN_MAX;
		}
		else {
			llTRLen = sl1TPos[liRNo] - llPos;
		}

		// 左のみ
		long long llMin = llJRLen;
		if (llJLLen < llTLLen) {
			llMin = llTLLen;
		}
		else {
			llMin = llJLLen;
		}

		// 右のみ
		long long llLen;
		if (llJRLen < llTRLen) {
			llLen = llTRLen;
		}
		else {
			llLen = llJRLen;
		}
		if (llMin > llLen) {
			llMin = llLen;
		}

		// 左の神社 + 右の寺
		llLen = llJLLen * 2 + llTRLen;
		if (llMin > llLen) {
			llMin = llLen;
		}

		// 右の神社 + 左の寺
		llLen = llJRLen * 2 + llTLLen;
		if (llMin > llLen) {
			llMin = llLen;
		}

		// 左の寺 + 右の神社
		llLen = llTLLen * 2 + llJRLen;
		if (llMin > llLen) {
			llMin = llLen;
		}

		// 右の寺 + 左の神社
		llLen = llTRLen * 2 + llJLLen;
		if (llMin > llLen) {
			llMin = llLen;
		}

		// 結果 - セット
		sprintf(lc1Out, "%lld\n", llMin);

		// 結果 - 表示
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
		if (strcmp(lc1Buf, lc1Out)) {
			siRes = -1;
		}
#else
		printf("%s", lc1Out);
#endif
	}

	return 0;
}

// １回実行
int
fOne(
)
{
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
	fMain();

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
	fOne(0);
#endif

	return 0;
}
