#include <stdio.h>

int main(void)
{
	int n;
	int i;
	int count;
	
	while (scanf("%d", &n)){
		if (n == 0){
			break;
		}
		
		count = 0;
		while (n > 1){
			if (n % 2 == 0){
				n /= 2;
				count++;
			}
			else if (n % 2 != 0){
				n = n * 3 + 1;
				count++;
			}
		}
		printf("%d\n", count);
	}
	
	return (0);
}
