#include <stdio.h>

int main(void)
{
	int w, h, n;
	int bex, bey, mapx, mapy,x;
	int sum = 0;
	
	scanf("%d %d %d", &w, &h, &n);
	
	for (x = 0; x < n; x++) {
		scanf("%d %d", &mapx, &mapy);
		if (x != 0) {
			while (1) {
				if (mapx == bex && mapy == bey) {
					break;
				}
				if (mapx > bex && mapy > bey) {
					bex++;
					bey++;
				}
				else if (mapx < bex && mapy < bey) {
					bex--;
					bey--;
				}
				else if (mapx > bex) {
					bex++;
				}
				else if (mapx < bex) {
					bex--;
				}
				else if (mapy > bey) {
					bey++;
				}
				else if (mapy < bey) {
					bey--;
				}
				sum++;
			}
		}
		bex = mapx;
		bey = mapy;
	}
	printf("%d\n", sum);
	
	return (0);
}
