#include <stdio.h>

int main(void)
{
	int n;
	int c;
	
	while (1){
		c = 0;
		
		scanf("%d", &n);
		
		if (n == 0){
			break;
		}
		while (n != 1){
		
			if (n % 2 == 0){
				n = n / 2;
				c++;
			}	
			else if(n % 2 == 1){
				n = n * 3 + 1;
				c++;
			}
		}
	
		printf("%d\n", c);
	
	}
	
	return (0);
	
}
