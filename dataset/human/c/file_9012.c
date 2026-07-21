#include <stdio.h>

int main(void)
{
	int n;
	int cnt;
	
	
	while (1){
		cnt = 0;
		
		scanf("%d", &n);
		
		if (n == 0){
			break;
		}
		
		while (n != 1){
			if (n % 2 == 0){
				n /= 2;
				cnt++;
				//printf("%d\n", n);
			}
			
			else {
				n = n * 3 + 1;
				cnt++;
				//printf("%d\n", n);
			}
			
		}
		printf("%d\n", cnt);
	}
	
	return (0);
}
