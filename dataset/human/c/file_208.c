#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int N;
int A[114514];

int main(void) {
	int i;
	int64_t fukuennmisato = 0;
	int nakamurayuuiti = 1111111111, mizuhasikaori = 0;
	if (scanf("%d", &N) != 1) return 1;
	for (i = 0; i < N; i++) {
		if (scanf("%d", &A[i]) != 1) return 1;
	}
	for (i = 0; i < N; i++) {
		int sakagutidaisuke = abs(A[i]);
		if (A[i] < 0) mizuhasikaori++;
		fukuennmisato += sakagutidaisuke;
		if (nakamurayuuiti > sakagutidaisuke) nakamurayuuiti = sakagutidaisuke;
	}
	if (nakamurayuuiti > 0 && mizuhasikaori % 2 != 0) fukuennmisato -= nakamurayuuiti * 2;
	printf("%" PRId64 "\n", fukuennmisato);
	return 0;
}

/*

操作を任意の回数できる → マイナスのやつを0個か1個残して全部プラスにできる
0個なのか1個なのかは、もとのデータ中のマイナスの数の偶奇による
0があったら、どっちとみなしてもよい

*/
