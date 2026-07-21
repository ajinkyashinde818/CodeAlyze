#include<stdio.h>
int main(void) {
	int E, Y;
	scanf("%d %d", &E, &Y);
	switch (E) {
	case 0:
			if (1868 <= Y&&Y <= 1911) {
				printf("M%d\n", Y - 1867);
			}
			else if (1912 <= Y&&Y <= 1925) {
				printf("T%d\n", Y - 1911);
			}
			else if (1926 <= Y&&Y <= 1988) {
				printf("S%d\n", Y - 1925);
			}
			else {
				printf("H%d\n", Y - 1988);
			}
			break;
	case 1:
		if (1 <= Y&&Y <= 44) {
			printf("%d\n", Y + 1867);
		}
			break;
	case 2:
		if (1 <= Y&&Y <= 14) {
			printf("%d\n", Y + 1911);
		}
		break;
	case 3:
		if (1 <= Y&&Y <= 63) {
			printf("%d\n", Y + 1925);
		}
			break;
	case 4:
		if (1 <= Y) {
			printf("%d\n", Y + 1988);
		}
		break;
	}
	return 0;
}
