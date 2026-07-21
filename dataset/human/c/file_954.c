#include <stdio.h>

int main(void) {
	int E, Y;
	int start = 0;
	int wareki = '?';
	if (scanf("%d%d", &E, &Y) != 2) return 1;
	if (E == 0) {
		if (Y <= 1911) { start = 1868; wareki = 'M'; }
		else if (Y <= 1925) { start = 1912; wareki = 'T'; }
		else if (Y <= 1988) { start = 1926; wareki = 'S'; }
		else { start = 1989; wareki = 'H'; }
		printf("%c%d\n", wareki, Y - start + 1);
	} else {
		switch (E) {
			case 1: start = 1868; break;
			case 2: start = 1912; break;
			case 3: start = 1926; break;
			case 4: start = 1989; break;
		}
		printf("%d\n", Y - 1 + start);
	}
	return 0;
}
