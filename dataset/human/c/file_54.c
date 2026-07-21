#include <stdio.h>


int main() {
	int r, g, b, c,d,e, n, j, k, l,z=0;

	scanf("%d %d %d %d", &r, &g, &b, &n);
	j = n / r;
	k = n / g;
	l = n / b;
	
	for (c = 0; c <= j;c++) {
		for (d = 0; d <= k;d++) {
			
				if ((n-r * c - g * d)%b==0 && (n-r * c - g * d)>=0)
					z++;
			
		
		}
	}



	printf("%d", z);

	return 0;

}
