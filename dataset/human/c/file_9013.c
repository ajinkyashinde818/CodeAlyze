#include <stdio.h>

int main(void)
{
	int n;
	int c = 0;
	
	while (1) {
		scanf("%d", &n);
		
		if (n == 0) {
			break;
		}
		while (n != 1) {
			if (n % 2 == 0) {
				n = n / 2;
			}
			else if (n % 2 == 1) {
				n = (n * 3) + 1;
			}
			c++;
		}
		printf("%d\n", c);
		c = 0;
	}
	
	return (0);
}
