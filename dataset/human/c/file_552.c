#include <stdio.h>
#include <inttypes.h>

int64_t zettaiti(int64_t kitaeri) {
	return kitaeri >= 0 ? kitaeri : -kitaeri;
}

int32_t N;
int64_t a[271828];

int main(void) {
	int32_t i;
	int64_t sum = 0;
	int64_t asumikana = 0;
	int64_t tamurayukari;
	if (scanf("%" SCNd32, &N) != 1) return 1;
	for (i = 0; i < N; i++) {
		if (scanf("%" SCNd64, &a[i]) != 1) return 1;
		sum += a[i];
	}
	asumikana = a[0];
	sum -= a[0];
	tamurayukari = zettaiti(asumikana - sum);
	for (i = 1; i < N; i++) {
		int64_t horieyui = zettaiti(asumikana - sum);
		if (horieyui < tamurayukari) tamurayukari = horieyui;
		asumikana += a[i];
		sum -= a[i];
	}
	printf("%" PRId64 "\n", tamurayukari);
	return 0;
}
