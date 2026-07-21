#include <stdio.h>

int main(void)

{
	int w, h, n;
	int fx, fy, x, y;
	int sum = 0;
	int i, j;
	int dx, dy;

	scanf("%d %d %d", &w, &h, &n);

	scanf("%d %d", &fx, &fy);
	for (i = 1; i < n; i++){
		scanf("%d %d", &x, &y);
		dx = fx - x;
		dy = fy - y;

		if (dx < 0){
			dx *= -1;
		}
		if (dy < 0){
			dy *= -1;
		}

		if (fx > x && fy > y){
			
			sum += (dx + dy);
			if (dx < dy){
				sum -= dx;
			}
			else {
				sum -= dy;
			}
		}
		else if (fx < x && fy < y){
			sum += (dx + dy);
			if (dx < dy){
				sum -= dx;
			}
			else {
				sum -= dy;
			}
		}
		else {
			sum += (dx + dy);
		}
		fx = x;
		fy = y;
	}
	printf("%d\n", sum);

	return (0);
}
