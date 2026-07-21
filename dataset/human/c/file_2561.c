#include <stdio.h>

int main() {
	int sum = 0;

	char s[3];
	scanf("%s", s);

	for(int i = 0; i < 3; ++i) {
		switch(s[i]) {
			case 'a':
				sum += 1;
				break;
			case 'b':
				sum += 10;
				break;
			case 'c':
				sum += 100;
				break;
		}
	}

	if (sum == 111) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}

	return 0;
}
