#include <stdio.h>

int main() {
	int N = 0;
	int i = 0;
	int flag = 0, flag1 = 0, flag2 = 0;
	int result1[102] = {};
	int result2[102] = {};
	scanf("%d", &N);
	for (i = 0; i <= N; i++) {
		scanf("%d %d", &result1[i], &result2[i]);
	}
	for (i = 0; i <= N; i++) {
		if (result1[i + 2] == 0) {
			break;
		}

		if (result1[i] == result2[i]) {
			flag = 1;
		}

		if (flag) {
			if (result1[i + 1] == result2[i + 1]) {
				flag1 = 1;
			}
			else {
				flag = 0;
			}
		}

		if (flag1) {
			if (result1[i + 2] == result2[i + 2]) {
				flag2 = 1;
				break;
			}
			else {
				flag = 0;
				flag1 = 0;
			}
		}
	}
	if (flag2) {
		printf("Yes");
	}
	else {
		printf("No");
	}
	return 0;
}
