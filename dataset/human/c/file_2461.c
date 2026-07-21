#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	int i, j, k;
	char S[4];
	scanf("%s", &S);

	int x = 0;
	for (i = 0; i <= 3; i++) {
		if (S[i] == 'a') {
			for (j = 0; j <= 3; j++) {
				if (S[j] == 'b') {
					for (k = 0; k <= 3; k++) {
						if (S[k] == 'c') {
							printf("Yes\n");
							x = 1;
						}

					}
				}
			}
		}
	}

	if (x == 0)
	{
		printf("No\n");
	}
	return 0;
}
