#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 内部定数
#define D_SIZE_MAX		1005									// 最大サイズ
#define D_HEAP_MAX		D_SIZE_MAX * D_SIZE_MAX * 2				// 最大ヒープ数

// 内部構造体 - ヒープ情報
typedef struct Heap {
	int miWCnt;													// ワープ数
	int miX, miY;												// 位置
} Heap;

// 内部変数
static FILE *szpFpI;											// 入力
static int siW, siH;											// 幅・高さ
static char sc2Mass[D_SIZE_MAX][D_SIZE_MAX];					// マス
static int si2WCnt[D_SIZE_MAX][D_SIZE_MAX];						// ワープ数
static Heap sz1Heap[D_HEAP_MAX];								// ヒープ
static int siHCnt;												// ヒープ数

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

// ヒープ - 比較 - ワープ数昇順
int
fHeapCmp(
	int piNo1					// <I> 配列番号１ 0～
	, int piNo2					// <I> 配列番号２ 0～
)
{
	// ワープ数昇順
	if (sz1Heap[piNo1].miWCnt < sz1Heap[piNo2].miWCnt) {
		return -1;
	}
	else if (sz1Heap[piNo1].miWCnt > sz1Heap[piNo2].miWCnt) {
		return 1;
	}

	return 0;
}

// ヒープ - 親子関係チェック
// 戻り値：[>=0]:変更した子の配列番号 [-1]:変更なし
int
fHeapChk(
	int piPNo					// <I> 親の配列番号 0～
)
{
	int liRet;

	// 最小値
	int liMNo = piPNo;

	// 左の子と比較
	int liCNo = piPNo * 2 + 1;
	if (liCNo < siHCnt) {
		liRet = fHeapCmp(liMNo, liCNo);
		if (liRet == 1) {
			liMNo = liCNo;
		}
	}

	// 右の子と比較
	liCNo = piPNo * 2 + 2;
	if (liCNo < siHCnt) {
		liRet = fHeapCmp(liMNo, liCNo);
		if (liRet == 1) {
			liMNo = liCNo;
		}
	}

	// 変更有無
	if (piPNo == liMNo) {
		return -1;
	}

	// 値の交換
	Heap lzWork;
	memcpy(&lzWork, &sz1Heap[liMNo], sizeof(Heap));
	memcpy(&sz1Heap[liMNo], &sz1Heap[piPNo], sizeof(Heap));
	memcpy(&sz1Heap[piPNo], &lzWork, sizeof(Heap));

	return liMNo;
}

// ヒープ - キュー追加
int
fHeapEnqueue(
	int piWCnt					// <I> ワープ回数
	, int piX					// <I> 位置X
	, int piY					// <I> 位置Y
)
{
	int liRet;

	// 範囲外
	if (piX < 0 || siW <= piX) {
		return 0;
	}
	if (piY < 0 || siH <= piY) {
		return 0;
	}

	// 道以外
	if (sc2Mass[piY][piX] != '.') {
		return 0;
	}

	// ワープ回数
	if (si2WCnt[piY][piX] <= piWCnt) {
		return 0;
	}
	si2WCnt[piY][piX] = piWCnt;

	// 末尾に追加
	sz1Heap[siHCnt].miWCnt = piWCnt;
	sz1Heap[siHCnt].miX = piX;
	sz1Heap[siHCnt].miY = piY;
	siHCnt++;

	// 親子関係チェック
	int liNo = siHCnt - 1;
	while (1) {

		// 親の配列番号
		liNo = (liNo - 1) / 2;

		// 親子関係チェック
		liRet = fHeapChk(liNo);
		if (liRet < 0) {
			break;
		}
	}

	return 0;
}

// ヒープ - キュー取得
int
fHeapDequeue(
	Heap *pzpRet				// <O> 取得先
)
{
	// データ数
	if (siHCnt < 1) {
		return -1;
	}

	// 取得
	memcpy(pzpRet, &sz1Heap[0], sizeof(Heap));
	siHCnt--;

	// データ数
	if (siHCnt < 1) {
		return 0;
	}

	// 末尾を先頭へ
	memcpy(&sz1Heap[0], &sz1Heap[siHCnt], sizeof(Heap));

	// 親子関係チェック
	int liNo = 0;
	while (liNo >= 0) {
		liNo = fHeapChk(liNo);
	}

	return 0;
}

// 実行メイン
int
fMain(
)
{
	int i, j, liRet;
	char lc1Buf[1024];

	// データ - 初期化
	siHCnt = 0;

	// 幅・高さ - 取得
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &siH, &siW);

	// ワープ数 - 初期化
	for (i = 0; i < siH; i++) {
		for (j = 0; j < siW; j++) {
			si2WCnt[i][j] = INT_MAX;
		}
	}

	// スタート - 取得
	int liSx, liSy;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &liSy, &liSx);
	liSx--;
	liSy--;

	// ゴール - 取得
	int liGx, liGy;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &liGy, &liGx);
	liGx--;
	liGy--;

	// マス - 取得
	for (i = 0; i < siH; i++) {
		fgets(sc2Mass[i], sizeof(sc2Mass[0]), szpFpI);
	}

	// スタート位置 - 登録
	fHeapEnqueue(0, liSx, liSy);

	// ヒープがなくなるまでループ
	while (1) {
		Heap lzHeap;
		liRet = fHeapDequeue(&lzHeap);
		if (liRet != 0) {
			break;
		}

		// 最短ではない
		if (lzHeap.miWCnt != si2WCnt[lzHeap.miY][lzHeap.miX]) {
			continue;
		}

		// 徒歩
		fHeapEnqueue(lzHeap.miWCnt, lzHeap.miX + 1, lzHeap.miY);
		fHeapEnqueue(lzHeap.miWCnt, lzHeap.miX - 1, lzHeap.miY);
		fHeapEnqueue(lzHeap.miWCnt, lzHeap.miX, lzHeap.miY + 1);
		fHeapEnqueue(lzHeap.miWCnt, lzHeap.miX, lzHeap.miY - 1);

		// ワープ
		for (i = -2; i <= 2; i++) {
			for (j = -2; j <= 2; j++) {
				fHeapEnqueue(lzHeap.miWCnt + 1, lzHeap.miX + i, lzHeap.miY + j);
			}
		}
	}

	return si2WCnt[liGy][liGx];
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
	if (liRet == INT_MAX) {
		sprintf(lc1Buf, "-1\n");
	}
	else {
		sprintf(lc1Buf, "%d\n", liRet);
	}
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
