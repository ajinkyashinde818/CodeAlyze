#include<stdio.h>

int main() {
	char s[3];
	int i, n = 0;
	scanf("%s", s);
	for (i = 0; i < 3; i++) {
		if (s[i] == 'a') {
			n = n + 1;
			break;
		}
	}
	for (i = 0; i < 3; i++) {
		if (s[i] == 'b') {
			n = n + 2;
			break;
		}
	}
	for (i = 0; i < 3; i++) {
		if (s[i] == 'c') {
			n = n + 3;
			break;
		}
	}
	if (n == 6)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
