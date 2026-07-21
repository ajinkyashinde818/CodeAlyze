#include <stdio.h>

int max(int a, int b);

int main(void)
{
	int w, h, n, i, j, cost = 0;
	int sx,  sy, gx, gy;
	
	scanf("%d %d %d", &w, &h, &n);
	
	scanf("%d %d", &sx, &sy);
	
	for (i = 1; i < n; i++){
		
		scanf("%d %d", &gx, &gy);
		
		if (sx < gx && sy < gy){
			if (gx - sx < gy - sy){
				cost += gx - sx;
				sy += gx - sx;
				sx = gx;
			}
			else{
				cost += gy - sy;;
				sx += gy - sy;
				sy = gy;
			}
		}
		else if (sx > gx && sy > gy){
			if (sx - gx < sy - gy){
				cost += sx - gx;
				sy -= sx - gx;
				sx = gx;
			}
			else{
				cost += sy - gy;;
				sx -= sy - gy;
				sy = gy;
			}
		}
		cost += max(sx - gx, gx - sx);
		cost += max(sy - gy, gy - sy);
		sx = gx;sy = gy;
	}
	printf("%d\n", cost);
	
	return (0);
}

int max(int a, int b)
{
	if (a > b) return (a);
	
	else return (b);
}
