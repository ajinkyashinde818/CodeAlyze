#include <stdio.h>
int main(void) {
	int x, y;
	int j, i;

	while (1) {
		scanf("%d %d", &x, &y);
		if (x == 0 && y == 0)
			break;

		i = 0;
		j = 0;

		while (1) {
			while (1) {
				putchar('#'); i++;
				if (i == y){
					putchar('\n');
					i = 0;
					j++;
					break;
				}
				putchar('.'); i++;
				if (i == y)
				{
					putchar('\n');
					j++;
					i = 0;
					break;
				}
			}

			if (j == x)
				break;

			while (1) {
				putchar('.'); i++;
				if (i == y){
					putchar('\n');
					j++;
					i = 0;
					break;
				}
				putchar('#'); i++;
				if (i == y)
				{
					putchar('\n');
					j++;
					i = 0;
					break;
				}
			}
			if (j == x) 
				break;
			
		}
		putchar('\n');
	}
	return 0;
}
