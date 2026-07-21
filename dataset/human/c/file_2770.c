#include<stdio.h>
#include<string.h>

int main(void) {
	
	int i, j, z;
	int k, s;
	int cases = 0;

	scanf("%d%d", &k, &s);

	for (i = 0; i <= k; i++) {
		for (j = 0; j <= k; j++) {
			z = s - i - j;
			if (0 <= z && z <= k) {
				cases++;
			}
		}
	}

	printf("%d", cases);

	

	return 0;
}
