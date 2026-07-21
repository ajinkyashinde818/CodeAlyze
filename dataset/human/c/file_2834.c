#include <stdio.h>

int max(int a, int b){return a > b ? a : b;}
int min(int a, int b){return a < b ? a : b;}

int main(void){
	int k, s;
	int count = 0;
	scanf("%d %d", &k, &s);
	for(int x = max(s - 2 * k, 0); x <= k; x++){
		count += max(min(s - x, k) - max(s - x - k, 0) + 1, 0);
		//printf("%d\n", max(min(s - x, k) - max(s - x - k, 0) +1, 0));
	}
	printf("%d\n", count);
	return 0;
}
