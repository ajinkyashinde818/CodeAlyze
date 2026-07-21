#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 内部定数
#define D_CHAR_MAX		300005									// 最大文字数
#define D_LST_MAX		D_CHAR_MAX								// 最大リスト数

// 内部構造体 - リスト情報
typedef struct Lst {
	char mcChar;												// 文字
	struct Lst *mzpPrev;										// リスト - 前
	struct Lst *mzpNext;										// リスト - 次
} Lst;

// 内部変数
static FILE *szpFpI;											// 入力
static Lst sz1Lst[D_LST_MAX];									// リスト
static int siLCnt;												// リスト数
static char sc1Out[D_CHAR_MAX];									// 出力内容

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

// リスト - 取得
Lst *
fLstGet(
)
{
	Lst *lzpRet = &sz1Lst[siLCnt];
	siLCnt++;

	// クリア
	memset(lzpRet, 0, sizeof(Lst));

	return lzpRet;
}

// リスト - 追加 - 先頭
int
fLstAddFirst(
	Lst **pzppLstFirst			// <O> リスト - 先頭
	, Lst **pzppLstLast			// <O> リスト - 末尾
)
{
	// リスト - 取得
	Lst *lzpLst = fLstGet();

	// リスト - 先頭
	if (*pzppLstFirst != NULL) {
		(*pzppLstFirst)->mzpPrev = lzpLst;
		lzpLst->mzpNext = *pzppLstFirst;
	}
	*pzppLstFirst = lzpLst;

	// リスト - 末尾
	if (*pzppLstLast == NULL) {
		*pzppLstLast = lzpLst;
	}

	return 0;
}

// リスト - 追加 - 末尾
int
fLstAddLast(
	Lst **pzppLstFirst			// <O> リスト - 先頭
	, Lst **pzppLstLast			// <O> リスト - 末尾
)
{
	// リスト - 取得
	Lst *lzpLst = fLstGet();

	// リスト - 先頭
	if (*pzppLstFirst == NULL) {
		*pzppLstFirst = lzpLst;
	}

	// リスト - 末尾
	if (*pzppLstLast != NULL) {
		(*pzppLstLast)->mzpNext = lzpLst;
		lzpLst->mzpPrev = *pzppLstLast;
	}
	*pzppLstLast = lzpLst;

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
	siLCnt = 0;
	Lst *lzpFirst = NULL;
	Lst *lzpLast = NULL;

	// 文字 - 取得
	char lcChar;
	while (1) {
		fscanf(szpFpI, "%c", &lcChar);
		if (lcChar < 'a' || 'z' < lcChar) {
			break;
		}

		// リスト - 追加 - 末尾
		fLstAddLast(&lzpFirst, &lzpLast);
		lzpLast->mcChar = lcChar;
	}

	// クエリ数 - 取得
	int liQCnt;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d", &liQCnt);

	// クエリ - 取得
	int liRev = 0;
	for (i = 0; i < liQCnt; i++) {
		int liTi, liFi;
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d %d %c", &liTi, &liFi, &lcChar);

		// 反転
		if (liTi == 1) {
			liRev = !liRev;
			continue;
		}

		// 追加
		liFi--;
		if ((liRev + liFi) % 2) {
			fLstAddLast(&lzpFirst, &lzpLast);
			lzpLast->mcChar = lcChar;
		}
		else {
			fLstAddFirst(&lzpFirst, &lzpLast);
			lzpFirst->mcChar = lcChar;
		}
	}

	// 出力内容 - セット
	if (liRev == 0) {
		for (i = 0; lzpFirst != NULL; i++) {
			sc1Out[i] = lzpFirst->mcChar;
			lzpFirst = lzpFirst->mzpNext;
		}
	}
	else {
		for (i = 0; lzpLast != NULL; i++) {
			sc1Out[i] = lzpLast->mcChar;
			lzpLast = lzpLast->mzpPrev;
		}
	}
	sc1Out[i] = '\n';
	sc1Out[i + 1] = '\0';

	// 出力
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
