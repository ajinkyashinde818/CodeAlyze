// ABC 158-D
// 2020.3.7 bal4u

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define gc() getchar_unlocked()
#define pc(c) putchar_unlocked(c)

int in() {   // 非負整数の入力
	int n = 0; int c;
	c = gc();
	do n = 10 * n + (c & 0xf); while ((c = gc()) >= '0');
	return n;
}

int ins(char *s) { // 文字列の入力　スペース以下の文字で入力終了
	char *p = s--;
	do *++s = gc();
	while (*s > ' ');
	*s = 0;
	return s - p;
}

char S[600005], *a, *b;

int main()
{
	int Q, rev, id, F, C;

	a = S+250000;
	b = a + ins(a);
	rev = 0;
	Q = in();
	while (Q--) {
		id = gc(), gc();
		if (id == '1') rev = !rev;
		else {
			F = gc(), gc();
			C = gc(), gc();
			if (F == '1') {
				if (rev) *b++ = C;
				else *--a = C;
			} else {
				if (rev) *--a = C;
				else *b++ = C;
			}
		}
	}
	if (rev) {
		while (b > a) pc(*--b);
	} else {
		while (a < b) pc(*a++);
	}
	pc('\n');
	return 0;
}
