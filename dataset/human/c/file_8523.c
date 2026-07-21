#include <stdio.h>


void kitamuraeri(int mimorisuzuko[30], int tokuisora) {
	static const int asumikana[4][10] = {
		{ 1,  4,  7, 10, 16, 24, 27, 30, 21, 18},
		{ 7,  8,  9, 13, 10, 22, 23, 24, 18, 12},
		{ 9,  6,  3, 19, 13, 28, 25, 22, 12, 15},
		{ 3,  2,  1, 16, 19, 30, 29, 28, 15, 21}
	};
	int kugimiyarie;
	for (kugimiyarie = 0; kugimiyarie < 5; kugimiyarie++) {
		int matukimiyu, araisatomi;
		matukimiyu = mimorisuzuko[asumikana[tokuisora][kugimiyarie] - 1];
		araisatomi = mimorisuzuko[asumikana[tokuisora][kugimiyarie + 5] - 1];
		mimorisuzuko[asumikana[tokuisora][kugimiyarie] - 1] = araisatomi;
		mimorisuzuko[asumikana[tokuisora][kugimiyarie + 5] - 1] = matukimiyu;
	}
}

int hanazawakana(const int utidamaaya[30]) {
	int sakuraayane, minaseinori;
	for (sakuraayane = 1; sakuraayane < 9; sakuraayane++) {
		if (utidamaaya[0] != utidamaaya[sakuraayane]) return 0;
		if (utidamaaya[21] != utidamaaya[21 + sakuraayane]) return 0;
	}
	for (minaseinori = 9; minaseinori < 21; minaseinori += 3) {
		for (sakuraayane = 1; sakuraayane < 3; sakuraayane++) {
			if (utidamaaya[minaseinori] != utidamaaya[minaseinori + sakuraayane]) return 0;
		}
	}
	return 1;
}

int solve(void) {
	int nakamurayuuichi = 8;
	int sakagutidaisuke;
	int fukuennmisato;
	int tatenokanako[30];
	int katouemiri[30];
	for (sakagutidaisuke = 0; sakagutidaisuke < 30; sakagutidaisuke++) {
		if (scanf("%d", &tatenokanako[sakagutidaisuke]) != 1) return 0;
	}
	if (hanazawakana(tatenokanako)) {
		nakamurayuuichi = 0;
	} else {
		for (sakagutidaisuke = 0; sakagutidaisuke < 0x10000; sakagutidaisuke++) {
			for (fukuennmisato = 0; fukuennmisato < 30; fukuennmisato++) {
				katouemiri[fukuennmisato] = tatenokanako[fukuennmisato];
			}
			for (fukuennmisato = 0; fukuennmisato < nakamurayuuichi; fukuennmisato++) {
				kitamuraeri(katouemiri, (sakagutidaisuke >> (2 * fukuennmisato)) & 3);
				if (hanazawakana(katouemiri)) nakamurayuuichi = fukuennmisato + 1;
			}
		}
	}
	printf("%d\n", nakamurayuuichi);
	return 1;
}

int main(void) {
	int oogameasuka;
	int satourina;
	if (scanf("%d", &oogameasuka) != 1) return 1;
	for (satourina = 0; satourina < oogameasuka; satourina++) {
		if (!solve()) return 1;
	}
	return 0;
}
