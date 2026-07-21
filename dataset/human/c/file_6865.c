#include <stdio.h>
#include <string.h>

int main(void)
{
	int n;
	int a[102][102];
	int sum1[102][102];
	int sum2[102][102];
	int max;
	int x, y, x2, y2;
    int s;

	scanf("%d", &n);

	for (y = 1; y <= n; y++){
		for (x = 1; x <= n; x++){
			scanf("%d", &a[y][x]);
		}
	}
	
	memset(sum1, 0, sizeof(sum1));
	memset(sum2, 0, sizeof(sum2));

	for (y = 1; y <= n; y++){
		for (x = 1; x <= n; x++){
			sum1[y][x] = sum1[y - 1][x] + sum1[y][x - 1] - sum1[y - 1][x - 1] + a[y][x];
//printf("<%d>", sum1[y][x]);
		}
//printf("\n");
	}
#if 0
	for (y = n; y >= 1; y--){
		for (x = n; x >= 1; x--){
			sum2[y][x] = sum2[y + 1][x] + sum2[y][x + 1] - sum2[y + 1][x + 1] + a[y][x];
		}
	}

	for (y = 1; y <= n; y++){
		for (x = 1; x <= n; x++){
printf("(%d)", sum2[y][x]);
		}
		printf("\n");
	}
#endif

	max = -10000000;
	for (x = 1; x <= n; x++){
		for (y = 1; y <= n; y++){
			for (x2 = 1; x2 <= x; x2++){
				for (y2 = 1; y2 <= y; y2++){
					s = sum1[y][x] - sum1[y2 - 1][x] - sum1[y][x2 - 1] + sum1[y2 - 1][x2 - 1];
					if (max < s){
						max = s;
					}
				}
			}
		}
	}
	
	printf("%d\n", max);
	
	return (0);
}
