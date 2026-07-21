// Aizu Vol-3 0337: Japanese Calendar
// 2017.8.25

#include <stdio.h>

int greg[] = { 1989, 1926, 1912, 1868, 0 };
char jan[] = { 'H', 'S', 'T', 'M', 0 };

int main()
{
	int E, Y, i;
	scanf("%d%d", &E, &Y);
	if (E == 0) {
		for (i = 0; greg[i] > 0; i++) {
			if (Y >= greg[i]) { printf("%c%d\n", jan[i], Y - greg[i] + 1); break; }
		}
	} else printf("%d\n", Y + greg[(4-E) & 3] - 1);
	return 0;
}
