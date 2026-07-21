#include <stdio.h>

int main(void)
{
	unsigned int ck_a, ck_b, ck_c;
	unsigned int ck_d;				/* 食べられるおいしいクッキー		*/

	scanf("%d %d %d", &ck_a, &ck_b, &ck_c);

	if ((ck_a + ck_b + 1) >= ck_c) {
		ck_d = ck_b + ck_c;
	} else {
		ck_d = ck_b + ck_a + ck_b + 1;
	}

	printf("%d\n", ck_d);

	return 0;
}
