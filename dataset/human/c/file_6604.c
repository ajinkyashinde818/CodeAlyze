#include <stdio.h>

int main(void) {
	int i = 0;

	int n = 0;

	int maxv = 0;	//?????§??????.
	int minv = 0;	//????°????.

	int buf = 0;

	scanf("%d", &n);

	scanf("%d", &minv);

	for (i = 1; i < n; i++) {
		scanf("%d", &buf);

		if (i == 1)
			maxv = buf - minv;

		maxv = maxv > buf - minv ? maxv : buf - minv;
		minv = minv < buf ? minv : buf;
	}

	printf("%d\n", maxv);

	return 0;
}
