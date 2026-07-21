#include <stdio.h>

int main(void)
{
	int n;
	int a;
	
	while (1){
		a = 0;
		
		scanf("%d", &n);
		
		if (n == 0){
			break;
		}
		while (n != 1){
			if (n % 2 == 0){
				n /= 2;
				a++;
			}
			else if (n % 2 == 1){
				n = n * 3 + 1;
				a++;
			}
		}
		printf("%d\n", a);
	}
	
	return (0);
}
