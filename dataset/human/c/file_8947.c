#include <stdio.h>

int main(void)
{
	int n = 1;
	int cou = 0;
	while (n != 0){
		scanf("%d", &n);
		if (n == 0){
			break;
		}
		while (n != 1){
			if (n % 2 == 0){
				n /= 2;
			}
			else {
				n = n * 3 + 1;
			}
			
			cou++;
		}
		printf("%d\n", cou);
		cou = 0;
	}
	
	return (0);
}
