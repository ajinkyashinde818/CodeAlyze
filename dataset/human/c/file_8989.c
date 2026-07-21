#include <stdio.h>

int main(void)
{
	int n, i;
	
	while (1){
		
		scanf("%d", &n);
		
		if (n == 0){
			break;
		}
		i = 0;
		while (1){
			
			if (n == 1){
				break;
			}
			
			if (n % 2 == 0){
				n /= 2;
				i++;
			}
			else {
				n = n * 3 + 1;
				i++;
			}
		
		}
		printf("%d\n", i);
	}
	
	return (0);
}
