#include<stdio.h>
int main() {
	int k, s,count=0;
	scanf("%d", &k);
	scanf("%d", &s);
	for (int x = 0; x <= k; x++) {
		for (int y = 0; y <= k; y++) {

			int z = s - x - y;
			if (0 <= z&&z <= k) {
				count++;
			}
		}
	}

	printf("%d\n", count);
	return(0);
}
