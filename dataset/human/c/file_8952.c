#include <stdio.h>

int main(void)
{
	int n;
	int i;
	int cnt;
	
	while (1){
		scanf("%d", &n);
		if (n == 0){
			break;
		}
	
		cnt = 0;
		while (n != 1){
			if (n % 2 == 0){
				n /= 2;
			}	
			else {
				n = n * 3 + 1;
			}
			cnt++;
		}
		printf("%d\n", cnt);
	}
	
	
	return (0);
}
