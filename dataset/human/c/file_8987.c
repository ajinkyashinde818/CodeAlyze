#include <stdio.h>

int main(void)
{
	int n;
	int c;
	
	c = 0;
	while (scanf("%d", &n) != EOF){
		if (n == 0){
			break;
		}
		else {
			for (;;){
				if (n == 1){
					printf("%d\n", c);
					c = 0;
					break;
				}
				else {
					if (n % 2 == 0){
						n = n / 2;
						c = c + 1;
					}
					else {
						n = (n * 3) + 1;
						c = c + 1;
					}
				}
			}
		}
	}
	
	return (0);
}
