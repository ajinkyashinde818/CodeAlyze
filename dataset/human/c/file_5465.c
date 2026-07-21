#include <stdio.h>
#define abs(x) (((x) < 0) ? ((x) * (-1)) : (x))

void warp(int *px, int *py, int x, int y, int w, int h, int *cou)
{
	int minx, miny, sx, sy, ret;
	
	minx = abs(x - *px);
	miny = abs(y - *py);
	sx = *px;
	sy = *py;
	ret = 0;
	
	while (1){
		if (x < *px){
			sx--;
			sy--;
//			printf("w[%d][%d]\n", sx, sy);
			ret++;
		}
		else if (x > *px){
			sx++;
			sy++;
//			printf("w[%d][%d]\n", sx, sy);
			ret++;
		}
		
		
//		printf("minx:%d, miny:%d, sx:%d, sy:%d, x:%d, y:%d, ret:%d\n", minx, miny, sx, sy, x, y, ret);
		
		if ((minx + miny) > (abs(x - sx) + abs(y - sy))){
			minx = abs(x - *px);
			miny = abs(y - *py);
			*px = sx;
			*py = sy;
		}
		else {
			break;
		}
		if ((sx <= w && sy <= h) && (sx > 0 && sy > 0)) break;
	}
	
	*cou += ret;
}

int main(void)
{
	int w, h, n, x[1000], y[1000];
	int i, j, px, py, sx, sy, cou;
	
	scanf("%d %d %d", &w, &h, &n);
	for (i = 0; i < n; i++){
		scanf("%d %d", &x[i], &y[i]);
	}
	
	px = x[0];
	py = y[0];
	cou = 0;
	i = 1;
	
	while (i < n){
		if ((x[i] > px && y[i] > py) || (x[i] < px && y[i] < py)){
//			printf("Start_warp %d %d %d %d %d\n", px, py, cou, x[i], y[i]);
			warp(&px, &py, x[i], y[i], w, h, &cou);
//			printf("End_warp %d %d %d %d %d\n", px, py, cou, x[i], y[i]);
		}
		else if (abs(x[i] - px) == abs(y[i] - py)){
			if ((x[i] - px) > 0){
				px++;
				cou++;
			}
			else if ((x[i] - px) < 0){
				px--;
				cou++;
			}
			if ((y[i] - py) > 0){
				py++;
				cou++;
			}
			else if ((y[i] - py) < 0){
				py--;
				cou++;
			}
			
//			printf("n[%d][%d]\n", px, py);
		}
		else if (abs(x[i] - px) < abs(y[i] - py) && abs(x[i] - px) != 0 || abs(y[i] - py) == 0 && abs(x[i] - px) != 0){
			if ((x[i] - px) > 0){
				px++;
//					printf("[%d][%d]\n", px, py);
			}
			else if ((x[i] - px) < 0){
				px--;
//					printf("[%d][%d]\n", px, py);
			}
			cou++;
			
		}
		else if (abs(x[i] - px) > abs(y[i] - py) && abs(y[i] - py) != 0 || abs(x[i] - px) == 0 && abs(y[i] - py) != 0){
			if ((y[i] - py) > 0){
				py++;
//					printf("[%d][%d]\n", px, py);
			}
			else if ((y[i] - py) < 0){
				py--;
//					printf("[%d][%d]\n", px, py);
			}
			cou++;
		}
		
		
		if (px == x[i] && py == y[i]){
			i++;
//				printf("i = %d, cou = %d, [[%d][%d]]\n", i, cou, px, py);
		}
	}
	
	printf("%d\n", cou);
	
	return (0);
}
