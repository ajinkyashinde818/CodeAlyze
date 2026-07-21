#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 内部定数
#define D_LV_MAX		10										// 最大難易度

// 内部構造体 - 難易度情報
typedef struct Lv {
	int miCnt;													// 問題数
	int miBonus;												// ボーナス
} Lv;

// 内部変数
static FILE *szpFpI;											// 入力
static Lv sz1Lv[D_LV_MAX + 5];									// 難易度
static int siLCnt;												// 難易度数
static int siGoal;												// 目標値
static int siMin;												// 最小問題数

// 内部変数 - テスト用
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
#endif

// 最小問題数 - 更新
int
fUpMin(
	int piScr					// <I> 累計スコア
	, int *pipCnt				// <I> 累計問題数
)
{
	int i;

	// 累計問題数
	int li1Cnt[D_LV_MAX + 5];
	memcpy(li1Cnt, pipCnt, sizeof(li1Cnt));

	// 目標値チェック
	int liLNo = siLCnt;
	while (piScr < siGoal) {
		if (li1Cnt[liLNo] < sz1Lv[liLNo].miCnt) {		// 未解答あり
			piScr += liLNo;
			li1Cnt[liLNo]++;

			if (li1Cnt[liLNo] == sz1Lv[liLNo].miCnt) {		// ボーナス
				piScr += sz1Lv[liLNo].miBonus;
			}
		}
		else {											// 未解答なし
			liLNo--;
		}
	}

	// 最終問題数
	int liSum = 0;
	for (i = 1; i <= siLCnt; i++) {
		liSum += li1Cnt[i];
	}

	// 最小問題数 - 更新
	if (siMin > liSum) {
		siMin = liSum;
	}

	return 0;
}

// ボーナスパターン - 作成
int
fMakeBonusPtn(
	int piLNo					// <I> 難易度 1～
	, int piScr					// <I> 累計スコア
	, int *pipCnt				// <I> 累計問題数
)
{
	// 終了チェック
	if (piLNo > siLCnt) {
		fUpMin(piScr, pipCnt);								// 最小問題数 - 更新
		return 0;
	}

	// ボーナス加算なし
	fMakeBonusPtn(piLNo + 1, piScr, pipCnt);			// 下位へ

	// ボーナス加算あり
	piScr += sz1Lv[piLNo].miBonus + piLNo * sz1Lv[piLNo].miCnt;
	pipCnt[piLNo] += sz1Lv[piLNo].miCnt;
	fMakeBonusPtn(piLNo + 1, piScr, pipCnt);			// 下位へ
	pipCnt[piLNo] -= sz1Lv[piLNo].miCnt;

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

	// データ - 初期化
	siMin = INT_MAX;											// 最小問題数

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

	// 難易度数・目標値 - 取得
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &siLCnt, &siGoal);
	siGoal /= 100;

	// 難易度 - 取得
	for (i = 1; i <= siLCnt; i++) {
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d%d", &sz1Lv[i].miCnt, &sz1Lv[i].miBonus);
		sz1Lv[i].miBonus /= 100;
	}
	
	// ボーナスパターン - 作成
	int li1Cnt[D_LV_MAX + 5];
	memset(li1Cnt, 0, sizeof(li1Cnt));
	fMakeBonusPtn(1, 0, li1Cnt);

	// 結果 - セット
	sprintf(lc1Out, "%d\n", siMin);

	// 結果 - 表示
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
