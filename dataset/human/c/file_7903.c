#include <stdio.h>

int getgcd(int a, int b) {
	if(b == 0)
		return a;
	return getgcd(b, a%b);
}

int main(void) {
	int n, m, a, i;
	scanf("%d%d", &n, &m);
	scanf("%d", &a);
	long lcm = a/2;
	for(i = 0; i < n - 1; i++) {
		scanf("%d", &a);
		int gcd = getgcd((int)lcm, a/2);
		if((lcm/gcd)%2 == 0 || (a/gcd)%4 == 0) {
			printf("0\n");
			return 0;
		}
		lcm = lcm*a/(2*gcd);
		if(m < lcm) {
			printf("0\n");
			return 0;
		}
	}
	printf("%d\n", (int)((m + lcm)/(2*lcm)));
	return 0;
}
