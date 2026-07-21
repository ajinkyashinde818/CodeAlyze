// AOJ 2681 arentheses
// 2018.3.19 bal4u

#include <stdio.h>
#include <stdlib.h>

// 高速数値入出力
#if 1
#define gc() getchar_unlocked()
#else
#define gc() getchar()
#endif
int in()  // 非負整数の入力
{
	int n = 0, c = gc();
	do n = 10 * n + (c & 0xf), c = gc(); while (c >= '0');
	return n;
}

int N;
// 各文字列の最も深いレベル（先頭からみた場合）、高いレベル（末尾から見た場合）、左右括弧の数の差
int deep[105], high[105], phase[105]; //　解釈は上の行
int sz;   // 処理すべき文字列の数
char buf[105];  // 入力受付用

int main()
{
	int i, k, c, h, d, s, total;
	int left, right;   // 先頭、末尾からみた場合のphaseの合計
	char *p, *q;

	N = in(); sz = left = right = total = 0;
	while (N--) {
		p = buf; while ((c = gc()) > ' ') *p++ = c;

		// 文字列の先頭からみた場合の様子。右括弧の相対的な多さの最大値がd
		d = 200, s = 0;
		q = buf - 1; while (++q < p) {
			if (*q == '(') total++, s++;
			else if (--s < d) d = s;
		}
		deep[sz] = d, phase[sz] = s;

		// 後ろからみた場合の様子。左括弧の相対的な多さの最大値がh
		h = -200, s = 0;
		while (--p >= buf) {
			if (*p == ')') total--, s--;
			else if (++s > h) h = s;
		}
		high[sz] = h;

		if (d >= 0) left += s;   // 右括弧の数がどの位置で切っても左側（先頭から）の左括弧より少ない。例 (())(
		else if (h <= 0) right += s; // 左括弧の数がどの位置で切っても右側（末尾から）の右括弧より少ない。例 ())()
		else sz++;  // それ以外
	}
	if (total != 0) goto No;   // 左右括弧の数にずれがあり
	if (sz == 0) goto Yes;     // 未処理文字列がない

	k = s = 0;
	for (i = 0; i < sz; i++) {
		if (deep[i] + left >= 0 && phase[i] >= 0) left += phase[i], k++;
		else if (high[i] + right <= 0 && phase[i] <= 0) right += phase[i], k++;
		else s = deep[i];
	}
	if (k == sz || (k == sz - 1 && left + s >= 0)) {
Yes:	puts("Yes");
	}
	else {
No:		puts("No");
	}
	return 0;
}
