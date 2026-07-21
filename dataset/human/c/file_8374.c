#include <stdio.h>
#include <string.h>

int main(void)
{
	int n, k;
	char s[256];
	scanf("%d", &n);
	scanf("%s", s);
	scanf("%d", &k);
	k--;
	for (int i = 0; i < n; i++) {
		if (s[i] != s[k]) {
			printf("*");
		} else {
			printf("%c", s[i]);
		}
	}

	return 0;
}
