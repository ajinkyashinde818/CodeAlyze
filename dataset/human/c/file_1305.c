#include <stdio.h>
#include <math.h>

int function(int i);

int main(void) {
	int p[8];
	int c[8] = {4,1,4,1,2,1,2,1};
	int min, cn, ms;
	int sum;
	int i, j;
	while(1) {
		for (i = 0; i < 8 && scanf(" %d", &p[i]) != EOF;i++);
		if (i != 8)
			break;
		for (i = 0, min = 99999; i < 8; i++) {
			for (j = 0, sum = 0; j < 8; j++) {
				if (p[j] - c[(i+j)%8] > 0)
					sum += p[j] - c[(i+j)%8];
			}
			if (min > sum) {
				min = sum;
				cn = i;
				for (j = 0, ms = 0; j < 8; j++) {
					ms += c[(i+j)%8] * function(7-j);
				}
			}
			else if (min == sum) {
				for (j = 0, sum = 0; j < 8; j++) {
					sum += c[(i+j)%8] * function(7-j);
				}
				if (sum < ms) {
					ms = sum;
					cn = i;
				}
			}
		}
		for (i = 0; i < 8; i++) {
			if (i)
				putchar(' ');
			printf("%d", c[(cn+i)%8]);
		}
		putchar('\n');
	}
	return 0;
}

int function(int i) {
	int sum = 1;
	for (; i > 0; i--)
		sum *= 10;
	return sum;
}
