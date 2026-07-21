#include <stdio.h>

int main() {
	int c[8], p[] = {4, 1, 4, 1, 2, 1, 2, 1};

	while(scanf("%d", &c[0]) != EOF) {
		int max = 0, max_p_index = 0;
		int i, j;

		for(i = 1; i < 8; i++)
			scanf("%d", &c[i]);

		for(i = 0; i < 8; i++) {
			int tmp = 0;
			for(j = 0; j < 8; j++) {
				if(c[j] < p[(i + j) % 8]) {
					tmp += c[j];
				}
				else {
					tmp += p[(i + j) % 8];
				}
			}

			if(max < tmp) {
				max = tmp;
				max_p_index = i;
			}

			else if(max == tmp) {
				int tmp_ = 0, tmp__ = 0;

				for(j = 0; j < 8; j++) {
					tmp_ *= 10;
					tmp_ += p[(max_p_index + j) % 8];
					tmp__ *= 10;
					tmp__ += p[(i + j) % 8];
				}

				if(tmp_ > tmp__)
					max_p_index = i;
			}
		}

		printf("%d", p[max_p_index]);
		for(i = 1; i < 8; i++)
			printf(" %d", p[(max_p_index + i) % 8]);
		putchar('\n');
	}

	return 0;
}
