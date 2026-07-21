#include <stdio.h>

int main() {
	char s[4];
	scanf("%s", &s);
	int a = 0, b = 0, c = 0;
	for (int i = 0; i < 4; i++) {
		switch (s[i]) {
		case 'a':
			a++;
			break;
		case 'b':
			b++;
			break;
		case 'c':
			c++;
			break;
		}
	}
	if ((a == 1) && (b == 1) && (c == 1)) printf("Yes\n");
	else printf("No\n");
}
