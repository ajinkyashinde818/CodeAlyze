#include <stdio.h>

int main(void)
{
	int n;
	int i;
	
	while (1){
		scanf("%d", &n);
		
		if (!n){
			break;
		}
		
		i = 0;
		while (n - 1){
			if (n % 2 == 1){
				n = n * 3 + 1;
			}
			else {
				n /= 2;
			}
			i++;
		}
		
		printf("%d\n", i);
	}
	
	return (0);
}
