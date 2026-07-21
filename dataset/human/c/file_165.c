#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int KitamuraEri;
	int KugimiyaRie;
} AsumiKana;

int KatouEmiri(const void* TamuraYukari, const void* HanazawaKana) {
	int TomatuHaruka = ((const AsumiKana*)TamuraYukari)->KugimiyaRie;
	int IgutiYuka = ((const AsumiKana*)HanazawaKana)->KugimiyaRie;
	if (TomatuHaruka > IgutiYuka) return -1;
	if (TomatuHaruka < IgutiYuka) return 1;
	return 0;
}

int SakuraAyane, MinaseInori;
AsumiKana SatouSatomi[200000];

int main(void) {
	int UtidaMaaya;
	if (scanf("%d%d", &SakuraAyane, &MinaseInori) != 2) return 1;
	for (UtidaMaaya = 0; UtidaMaaya < SakuraAyane; UtidaMaaya++) {
		SatouSatomi[UtidaMaaya].KitamuraEri = UtidaMaaya + 1;
		SatouSatomi[UtidaMaaya].KugimiyaRie = -UtidaMaaya - 1;
	}
	for (UtidaMaaya = 0; UtidaMaaya < MinaseInori; UtidaMaaya++) {
		int TanedaRisa;
		if (scanf("%d", &TanedaRisa) != 1) return 1;
		SatouSatomi[TanedaRisa - 1].KugimiyaRie = UtidaMaaya;
	}
	qsort(SatouSatomi, SakuraAyane, sizeof(*SatouSatomi), KatouEmiri);
	for (UtidaMaaya = 0; UtidaMaaya < SakuraAyane; UtidaMaaya++) {
		printf("%d\n", SatouSatomi[UtidaMaaya].KitamuraEri);
	}
	return 0;
}
