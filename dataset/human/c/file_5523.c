#include <stdio.h>

int t[1000000];
int main(void)
{
	int n, i, j, sum, c;	
	
	for (i = 2; i * i <= 1000000; i++){
		if (t[i] == 0){
			for (j = 2 * i; j <= 1000000; j++){
				if (j % i == 0){
					t[j] = 1;
				}
			}
		}
	}
	
	while (scanf("%d", &n), n != 0){
		sum = c = 0;
		
		for (i = 2; i <= 1000000; i++){
			if (t[i] == 0){
				sum += i;
				c++;
			}
			if (n == c){
				break;
			}
		}
		printf("%d\n", sum);
	}
	
	return 0;
}
