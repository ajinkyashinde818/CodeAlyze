#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 内部定数
#define D_CITY_MAX		200000									// 最大都市数
#define D_TFC_CNT		2										// 交通種類数
#define D_TFC_ROAD		0										// 交通 - 道路
#define D_TFC_RAIL		1										// 交通 - 鉄道
#define D_TREE_WCNT		2										// 木の方向数
#define D_TREE_LEFT		0										// 木の方向 - 左側
#define D_TREE_RIGHT	1										// 木の方向 - 右側

// 内部構造体 - 都市情報
typedef struct City {
	int mi1PNo[D_TFC_CNT];										// 親番号 1～
} City;

// 内部構造体 - 木構造
typedef struct Tree {
	int mi1PNo[D_TFC_CNT];										// 親番号 1～
	int miCnt;													// データ数
	int mi1Height[D_TREE_WCNT];									// 木の高さ
	struct Tree *mzp1Child[D_TREE_WCNT];						// 子
} Tree;

// 内部変数
static City sz1City[D_CITY_MAX + 5];							// 都市
static int siCCnt;												// 都市数
static Tree sz1Tree[D_CITY_MAX];								// 木の実データ
static int siTCnt;												// 木の実データ数
static Tree *szpTop;											// 先頭の木データ

// 内部変数 - テスト用
#ifdef D_TEST
	static FILE *szpFpT;
#endif

// 親番号 - 取得
int
fGetPNo(
	int piTfc					// <I> 道路 or 鉄道
	, int piCNo					// <I> 都市 1～
)
{
	// 親番号
	int liPNo = sz1City[piCNo].mi1PNo[piTfc];

	// 自身が親かチェック
	if (liPNo == piCNo) {
		return piCNo;
	}

	// 親番号取得・更新
	sz1City[piCNo].mi1PNo[piTfc] = fGetPNo(piTfc, liPNo);

	return sz1City[piCNo].mi1PNo[piTfc];
}

// 親番号 - 更新
int
fUpPNo(
	int piTfc					// <I> 道路 or 鉄道
	, int piCNo1				// <I> 都市１ 1～
	, int piCNo2				// <I> 都市２ 1～
)
{
	// 親番号取得
	int liPNo1 = fGetPNo(piTfc, piCNo1);
	int liPNo2 = fGetPNo(piTfc, piCNo2);

	// 同一かチェック
	if (liPNo1 == liPNo2) {
		return 0;
	}

	// 親番号更新
	sz1City[liPNo2].mi1PNo[piTfc] = liPNo1;

	return 0;
}

// 木データ - 作成
Tree *
fTreeMake(
	int *pipPNo					// <I> 親番号 1～
	, int piCnt					// <I> データ数
)
{
	// 対象の木データ
	Tree *lzpTree = &(sz1Tree[siTCnt]);
	siTCnt++;

	// データセット
	memset(lzpTree, 0, sizeof(Tree));					// 初期化
	lzpTree->mi1PNo[D_TFC_ROAD] = pipPNo[D_TFC_ROAD];	// 親番号 - 道路
	lzpTree->mi1PNo[D_TFC_RAIL] = pipPNo[D_TFC_RAIL];	// 親番号 - 鉄道
	lzpTree->miCnt = piCnt;								// データ数

	return lzpTree;
}

// 木データ - 比較
int
fTreeCmp(
	int *pipPNo					// <I> 親番号 1～
	, Tree *lzpTree				// <I> 木データ
)
{
	// 親番号 - 道路
	if (pipPNo[D_TFC_ROAD] < lzpTree->mi1PNo[D_TFC_ROAD]) {
		return -1;
	}
	else if (pipPNo[D_TFC_ROAD] > lzpTree->mi1PNo[D_TFC_ROAD]) {
		return 1;
	}

	// 親番号 - 鉄道
	if (pipPNo[D_TFC_RAIL] < lzpTree->mi1PNo[D_TFC_RAIL]) {
		return -1;
	}
	else if (pipPNo[D_TFC_RAIL] > lzpTree->mi1PNo[D_TFC_RAIL]) {
		return 1;
	}

	return 0;
}

// 木データ - 検索
Tree *
fTreeSrh(
	int *pipPNo					// <I> 親番号 1～
)
{
	// 先頭の木データ
	Tree *lzpNow = szpTop;

	// 検索
	while (1) {

		// データ有無
		if (lzpNow == NULL) {
			return NULL;
		}

		// 比較
		int liRet = fTreeCmp(pipPNo, lzpNow);
		if (liRet == 0) {								// 同一
			return lzpNow;
		}

		// 子へ移動
		if (liRet < 0) {								// 左側
			lzpNow = lzpNow->mzp1Child[D_TREE_LEFT];
		}
		else {											// 右側
			lzpNow = lzpNow->mzp1Child[D_TREE_RIGHT];
		}
	}

	return NULL;
}

// 木データ - 高さ取得
int
fTreeGetHeight(
	Tree *pzpTree				// <I> 対象の木情報
)
{
	// データ有無
	if (pzpTree == NULL) {
		return 0;
	}

	if (pzpTree->mi1Height[D_TREE_LEFT] >= pzpTree->mi1Height[D_TREE_RIGHT]) {
		return pzpTree->mi1Height[D_TREE_LEFT] + 1;
	}
	else {
		return pzpTree->mi1Height[D_TREE_RIGHT] + 1;
	}
}

// 木データ - 右回転(親は子の右下へ・子は親の左上へ)
int
fTreeRttR(
	Tree **pzppTree				// <I> 回転対象
)
{
	// 現在の子
	Tree *lzpChild = (*pzppTree)->mzp1Child[D_TREE_LEFT];

	// 右回転
	(*pzppTree)->mzp1Child[D_TREE_LEFT] = lzpChild->mzp1Child[D_TREE_RIGHT];	// 親の左側 = 子の右側
	(*pzppTree)->mi1Height[D_TREE_LEFT] = lzpChild->mi1Height[D_TREE_RIGHT];	// 親の高さ(左) = 子の高さ(右)
	lzpChild->mzp1Child[D_TREE_RIGHT] = *pzppTree;								// 子の右側 = 親
	lzpChild->mi1Height[D_TREE_RIGHT] = fTreeGetHeight(*pzppTree);				// 子の高さ(右) - 親の高さ
	*pzppTree = lzpChild;														// 親 = 子

	return 0;
}

// 木データ - 左回転(親は子の左下へ・子は親の右上へ)
int
fTreeRttL(
	Tree **pzppTree				// <I> 回転対象
)
{
	// 現在の子
	Tree *lzpChild = (*pzppTree)->mzp1Child[D_TREE_RIGHT];

	// 左回転
	(*pzppTree)->mzp1Child[D_TREE_RIGHT] = lzpChild->mzp1Child[D_TREE_LEFT];	// 親の右側 = 子の左側
	(*pzppTree)->mi1Height[D_TREE_RIGHT] = lzpChild->mi1Height[D_TREE_LEFT];	// 親の高さ(右) = 子の高さ(左)
	lzpChild->mzp1Child[D_TREE_LEFT] = *pzppTree;								// 子の左側 = 親
	lzpChild->mi1Height[D_TREE_LEFT] = fTreeGetHeight(*pzppTree);				// 子の高さ(左) - 親の高さ
	*pzppTree = lzpChild;														// 親 = 子

	return 0;
}

// 木データ - 追加・削除の共通処理
// 戻り値：[1]高さの変更あり [0]高さの変更なし
int
fTreeComAddDel(
	Tree **pzppNow				// <I> 現在の木情報
	, int piWay					// <I> 対象の方向
)
{
	// 高さの変更があるかチェック
	int liNew = fTreeGetHeight((*pzppNow)->mzp1Child[piWay]);
	if ((*pzppNow)->mi1Height[piWay] == liNew) {												// 変化なし
		return 0;
	}
	(*pzppNow)->mi1Height[piWay] = liNew;														// 更新

																								// 高さが離れている場合、回転
	if ((*pzppNow)->mi1Height[D_TREE_LEFT] - (*pzppNow)->mi1Height[D_TREE_RIGHT] > 1) {			// 左側が高い
		fTreeRttR(pzppNow);																			// 右回転
	}
	else if ((*pzppNow)->mi1Height[D_TREE_RIGHT] - (*pzppNow)->mi1Height[D_TREE_LEFT] > 1) {	// 右側が高い
		fTreeRttL(pzppNow);																			// 左回転
	}

	return 1;
}

// 木データ - 追加
// 戻り値：[1]高さの変更あり [0]高さの変更なし [-1]追加なし
int
fTreeAdd(
	Tree **pzppNow				// <I> 現在の木情報
	, int *pipPNo				// <I> 親番号 1～
	, int piCnt					// <I> データ数
)
{
	int liRet;

	// 作成
	if (*pzppNow == NULL) {
		*pzppNow = fTreeMake(pipPNo, piCnt);
		return 1;
	}

	// 比較
	liRet = fTreeCmp(pipPNo, *pzppNow);
	if (liRet == 0) {															// 同一
		(*pzppNow)->miCnt += piCnt;
		return -1;
	}

	// 方向の判別
	int liWay;
	if (liRet < 0) {															// 左側
		liWay = D_TREE_LEFT;
	}
	else {																		// 右側
		liWay = D_TREE_RIGHT;
	}

	// 下位へ
	liRet = fTreeAdd(&((*pzppNow)->mzp1Child[liWay]), pipPNo, piCnt);
	if (liRet < 1) {															// 高さの変更なし or 追加なし
		return liRet;
	}

	// 追加・削除の共通処理
	return fTreeComAddDel(pzppNow, liWay);
}

// 実行メイン
int
fMain(
	int piTNo					// <I> テスト番号 1～
)
{
	int i;
	char lc1Buf[1024];

	// データ初期化
	siTCnt = 0;													// 木の実データ数
	szpTop = NULL;												// 先頭の木データ
								
	// テストファイルオープン
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", piTNo);
	szpFpT = fopen(lc1Buf, "r");
#endif

	// 都市数・道路数・鉄道数取得
	int liDCnt, liRCnt;
#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
	fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
	sscanf(lc1Buf, "%d%d%d", &siCCnt, &liDCnt, &liRCnt);

	// 都市 - 親番号の初期化
	for (i = 1; i <= siCCnt; i++) {
		sz1City[i].mi1PNo[D_TFC_ROAD] = i;
		sz1City[i].mi1PNo[D_TFC_RAIL] = i;
	}

	// 道路取得
	for (i = 0; i < liDCnt; i++) {
		int liCNo1, liCNo2;
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
		sscanf(lc1Buf, "%d%d", &liCNo1, &liCNo2);

		// 親番号 - 更新
		fUpPNo(D_TFC_ROAD, liCNo1, liCNo2);
	}

	// 鉄道取得
	for (i = 0; i < liRCnt; i++) {
		int liCNo1, liCNo2;
#ifdef D_TEST
		fgets(lc1Buf, sizeof(lc1Buf), szpFpT);
#else
		fgets(lc1Buf, sizeof(lc1Buf), stdin);
#endif
		sscanf(lc1Buf, "%d%d", &liCNo1, &liCNo2);

		// 親番号 - 更新
		fUpPNo(D_TFC_RAIL, liCNo1, liCNo2);
	}

	// 都市の親番号を木データに登録
	for (i = 1; i <= siCCnt; i++) {

		// 親番号再取得
		sz1City[i].mi1PNo[D_TFC_ROAD] = fGetPNo(D_TFC_ROAD, i);
		sz1City[i].mi1PNo[D_TFC_RAIL] = fGetPNo(D_TFC_RAIL, i);

		// 木データに登録
		fTreeAdd(&szpTop, sz1City[i].mi1PNo, 1);
	}

	// １つ目の連結都市数を表示
	Tree *lzpTree = fTreeSrh(sz1City[1].mi1PNo);
	printf("%d", lzpTree->miCnt);

	// ２つ目以降の連結都市数を表示
	for (i = 2; i <= siCCnt; i++) {
		lzpTree = fTreeSrh(sz1City[i].mi1PNo);
		printf(" %d", lzpTree->miCnt);
	}

	// 改行
	printf("\n");

	// テストファイルクローズ
#ifdef D_TEST
	fclose(szpFpT);
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
