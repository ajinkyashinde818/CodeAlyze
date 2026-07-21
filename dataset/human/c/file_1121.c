#include <stdio.h>

typedef struct { int m; int c; int x; int i; } MCXI;

/* 標準入力からMCXI文字列を読み込む */
void scanMCXI(MCXI *a) {
	char s[9];
	int d, i;
	/* 初期化 */
	a->m = 0; a->c = 0; a->x = 0; a->i = 0;
	/* 入力 */
	scanf("%*[^mcxi2-9]%[mcxi2-9]", s);
	/* MCXIの書式に従って解析する */
	for (d = 1, i = 0; s[i] != '\0'; i++) {
		/* mxci符号 */
		if (s[i] == 'm') a->m = d;
		else if (s[i] == 'c') a->c = d;
		else if (s[i] == 'x') a->x = d;
		else if (s[i] == 'i') a->i = d;
		/* 数字 */
		if (s[i] >= '2' && s[i] <= '9') d = s[i] - '0';
		else d = 1; /* mcxiの前に数字がない場合は1であるので1で初期化する */
	}
}

/* 標準出力へMCXI文字列を書き出す */
void printMCXI(MCXI a) {
	if (a.m > 1) printf("%d", a.m); if (a.m > 0) printf("m");
	if (a.c > 1) printf("%d", a.c); if (a.c > 0) printf("c");
	if (a.x > 1) printf("%d", a.x); if (a.x > 0) printf("x");
	if (a.i > 1) printf("%d", a.i); if (a.i > 0) printf("i");
	printf("\n");
}

/* 2つのMCXI文字列の和を返す */
MCXI addMCXI(MCXI a, MCXI b) {
	MCXI s;
	/* 各位同士と繰り上がりを足し合わせる */
	s.i = a.i + b.i;
	s.x = a.x + b.x + s.i / 10;
	s.c = a.c + b.c + s.x / 10;
	s.m = a.m + b.m + s.c / 10;
	/* 繰り上がりを取り除く */
	s.m %= 10; s.c %= 10; s.x %= 10; s.i %= 10;
	return s;
}

int main(void) {
	int n; /* 計算指示の個数 */
	int i;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		MCXI a, b;
		scanMCXI(&a);
		scanMCXI(&b);
		printMCXI(addMCXI(a, b)); /* 和を出力する */
	}
    return 0;
}
