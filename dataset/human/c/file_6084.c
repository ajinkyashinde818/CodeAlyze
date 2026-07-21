#include <stdio.h>

int main(void) {
	int max = -0x80000000, bottom, now, before;
	scanf("%d", &before);
	scanf("%d", &before);
	bottom = before;
	while (scanf("%d", &now) != EOF) {
		if (max < now - bottom) max = now - bottom;
		if (now < before && bottom > now) bottom = now;
		before = now;
	}
	printf("%d\n", max);
}
