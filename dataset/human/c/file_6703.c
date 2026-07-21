#include<stdio.h>
int main()
{
	int a[501][501], c[501], h = 0;
	int i, i2, n, m, x, y;
	while (1){
		for (i = 0; i < 501; i++){
			for (i2 = 0; i2 < 501; i2++){
				a[i][i2] = 0;
			}
			c[i] = 0;
		}
	
	h = 0;
	c[1] = 1;
	c[0] = 1;
	scanf("%d %d", &n, &m);
	if (n == 0 && m == 0)break;
	for (i = 0; i < m; i++){
		scanf("%d %d", &x, &y);
		a[x][y] = 1;
		a[y][x] = 1;

	}
	for (i = 1; i <= n; i++){
		if (a[1][i] == 1){
			if (c[i] == 0){
				h++;
			}
			c[i] = 1;
			for (i2 = 1; i2 <= n; i2++){
				if (a[i][i2] == 1 && c[i2] == 0){
					c[i2] = 1;
					h++;
				}
			}
		}
	}
	printf("%d\n", h);
}
return 0;
}
