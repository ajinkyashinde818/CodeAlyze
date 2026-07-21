#include<stdio.h>
int main(void) {
	int a, b, k;
	int jo;
	int cnt = 0;

	scanf("%d %d %d", &a, &b, &k);
	
	jo = 100;
	while (jo > 0) {
		if (a % jo == 0 && b % jo == 0) {
			
			cnt++;
		}
		if (cnt == k) {
			break;
		}
		jo--;
	}
	printf("%d\n", jo);
	return 0;
}
