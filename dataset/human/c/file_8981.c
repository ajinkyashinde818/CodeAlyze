#include <stdio.h>

int main(void)
{
	int n;
	int count;
	
	while (1){
		count = 0;
		scanf("%d", &n);
		
		if (n == 0){
			break;
		}
		while (n != 1){
			if (n % 2 == 0){
				n /= 2;
				count++;
			}
			else if (n != 1){
				n *= 3;
				n += 1;
				count++;
			}
		}
		printf("%d\n", count);
	}
	
	return (0);
}
