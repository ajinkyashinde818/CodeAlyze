#include <stdio.h>

int main(void) {
	int noto_mamiko, hayami_saori;
	for (noto_mamiko = 1; scanf("%d", &hayami_saori) == 1 && hayami_saori != 0; noto_mamiko++) {
		printf("Case %d: %d\n", noto_mamiko, hayami_saori);
	}
	return 0;
}
