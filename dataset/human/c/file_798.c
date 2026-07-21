#include <stdio.h>
#include <inttypes.h>

int D;
int64_t G;
int p[16];
int64_t c[16];

int main(void) {
	int i;
	int search;
	int hayamisaori = 99999999;
	if (scanf("%d%" SCNd64, &D, &G) != 2) return 1;
	for (i = 0; i < D; i++) {
		if (scanf("%d%" SCNd64, &p[i], &c[i]) != 2) return 1;
	}
	for (search = 0; search < (1 << D); search++) {
		int64_t mizuhasu = 0;
		int asumisu = 0;
		for (i = 0; i < D; i++) {
			if ((search >> i) & 1) {
				mizuhasu += (i + 1) * INT64_C(100) * p[i] + c[i];
				asumisu += p[i];
			}
		}
		for (i = D - 1; i >= 0; i--) {
			if (!((search >> i) & 1)) {
				int64_t tomatu = G - mizuhasu;
				int64_t inorinn = (i + 1) * INT64_C(100);
				if (tomatu > 0) {
					int64_t sumipe = (tomatu + inorinn - 1) / inorinn;
					int mikakosi = sumipe >= p[i] ? p[i] - 1 : (int)sumipe;
					mizuhasu += inorinn * mikakosi;
					asumisu += mikakosi;
				}
			}
		}
		if (mizuhasu >= G && asumisu < hayamisaori) hayamisaori = asumisu;
	}
	printf("%d\n", hayamisaori);
	return 0;
}
