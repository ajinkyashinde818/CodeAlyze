#include <stdio.h>

int main()
{
	int n;
	int k;
	char str[11];

	scanf("%d", &n);
	scanf("%s", str);
	scanf("%d", &k);

	for (int i = 0; i < n; i++) {
		if (str[i] == str[k - 1]) {
			putchar(str[i]);
		}
		else {
			putchar('*');
		}
	}

	return 0;
}
