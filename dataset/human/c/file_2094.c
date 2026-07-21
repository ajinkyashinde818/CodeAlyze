#include <stdio.h>

int main()
{
	char N[1000002];
	scanf("%s", N);
	
	int i, sum = 0, up = 0, tmp;
	for (i = 0; N[i] != 0; i++);
	for (i--; i >= 0; i--) {
		tmp = N[i] - '0' + up;
		if (tmp < 5) {
			sum += tmp;
			up = 0;
		} else if (tmp > 5) {
			sum += 10 - tmp;
			up = 1;
		} else {
			sum += 5;
			if (i == 0 || N[i-1] - '0' < 5) up = 0;
			else up = 1;
		}
	}
	printf("%d\n", sum += up);
	fflush(stdout);
	return 0;
}
