#include <stdio.h>

int main(void)
{
	int n;
	int i;
	
	while (1){
		
		scanf("%d", &n);
		
		if (n == 0){
			break;
		}
		
		i = 0;
		
		while (n != 1){
			
			if (n % 2 == 0){
				n /= 2;
			}
			
			else {
				n = (n * 3) + 1;
			}
			i++;
		}
		printf ("%d\n", i);
	}
	
	return (0);
	
}
