#include <stdio.h>

int main(void) {
	unsigned int A, B, C;
	unsigned int gedoku, kueru, oisii, oisikunai;
	if (scanf("%u%u%u", &A, &B, &C) != 3) return 1;
	gedoku = A + B;
	if (C <= gedoku + 1) {
		/* 全部食える */
		printf("%u\n", B + C);
	} else {
		/* 毒入りが残る */
		kueru = gedoku * 2 + 1;
		oisii = B * 2;
		oisikunai = oisii < kueru ? (kueru - oisii) / 2 : 0;
		printf("%u\n", kueru - oisikunai);
	}
	return 0;
}
