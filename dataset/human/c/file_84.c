#include<stdio.h>

int GCD(int a, int b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}
int main() {
	int i, j, k, f = 0, n, t, m, b, h, w, r, g;
	int r1, g1, b1;


	scanf("%d %d %d %d", &r, &g, &b, &n);

	r1 = n / r +1;
	g1 = n / g +1;
	b1 = n / b +1;

	
	for (i = 0;i < r1;i++) {
		for (j = 0;j < g1;j++) {	
			m = r * i + g * j;
			t = n - m;
			if (t%b == 0&&t>=0) {
				f = f + 1;
			
			}
		}
	}




	printf("%d",f);


	return 0;
}
