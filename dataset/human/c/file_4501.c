#include <stdio.h>

int main(void)
{
	int input[100][2] = {0};
	int i, n, zoro, max_zoro;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &input[i][0], &input[i][1]);
	}
	
	max_zoro = zoro = 0;
	for (i = 0; i < n; i++) {
		if (input[i][0] == input[i][1]) {
			zoro++;
		} else {
			zoro = 0;
		}
		if (zoro > max_zoro) {
			max_zoro = zoro;
		}
	}
	if (max_zoro >= 3) {
		printf("Yes");
    } else {
		printf("No");
	}

	return 0;
}
