#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(void)
{
	int r, g, b, n;
	int m, count = 0;
	scanf("%d %d %d %d", &r, &g, &b, &n);

	for (int red = 0; red <= n / r; red++) {
		for (int green = 0; green <= n / g; green++) {
			if ((n - r * red - g * green) >= 0 && (n - r * red - g * green) % b == 0) {
				m = (n - r * red - g * green) / b;
				if (r * red + g * green + m * b == n) ++count;
			}
		}
	}
	printf("%d\n", count);
	return 0;
}
