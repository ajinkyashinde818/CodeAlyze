#include <stdio.h>

int main(void)
{
	int a, b, k;
	int i;
	int min;
	int count = 0;
	
	scanf("%d%d%d", &a, &b, &k);
	
	if(a > b) {
		min = b;
	} else {
		min = a;
	}
	
	for(i = min; i > 0; i--) {
		if( (a % i == 0) && (b % i == 0) ) {
			count++;
			if(count == k) {
				printf("%d", i);
				return 0;
			}
		}
	}
	
	return 0;
}
