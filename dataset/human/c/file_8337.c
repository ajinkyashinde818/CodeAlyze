#include <stdio.h>

int main() {

	int n, k;
	char check, S[11];

	scanf("%d", &n);
	scanf("%s",  S);
	scanf("%d", &k);
	check = S[k - 1];

	for (int i = 0; S[i] != '\0'; i++) {
		if (S[i] != check)
			S[i] = '*';
	}
	printf("%s", S);
	return 0;
}
