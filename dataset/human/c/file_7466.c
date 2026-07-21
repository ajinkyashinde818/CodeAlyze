#include <stdio.h>

int main(void)
{
	int i = 0, data[100000] ={0}, j;
	
	for(i = 0; i <= 99999; i++) {
		scanf("%d", &data[i]);
		if (data[i] == 0) {
			break;
		}
	}
	
	for (j = 0; j < i; j++) {
		printf("Case %d: %d\n", j+1, data[j]);
	}
	
	return 0;
}
