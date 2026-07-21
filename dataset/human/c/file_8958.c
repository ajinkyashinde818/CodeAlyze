#include <stdio.h>

int main(void)
{
	int n;
	int c;
	
	while (1){
		scanf("%d", &n);
		c = 0;
		
		if (n == 0){
			break;
		}
		
		while (n != 1){
			if (n % 2 == 0){
				n /= 2;
			}
			else if (n % 2 != 0){
				n *= 3;
				n += 1;
			}
			c++;
		}
		printf("%d\n", c);
		
	}
	
	return (0);
}
