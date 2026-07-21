#include <stdio.h>

int main(int argc, char const *argv[])
{
	int w,h;
	int i,j;
	while (1) {
		scanf("%d %d", &h, &w);
		if(h == 0 && w == 0)
		break;
		for (i = 0; i < h; ++i)	{
			for (j = 0; j < w; ++j) {
				// 奇数行,奇数列のとき
				if(i % 2 == 0 && j % 2 == 0) {
					printf("#");
					// 奇数行,偶数列のとき
				} else if (i % 2 == 0 && j % 2 != 0) {
					printf(".");
					// 偶数行,奇数列のとき
				} else if (i % 2 != 0 && j % 2 != 0) {
					printf("#");
					// そうでないとき
				} else {
					printf(".");
				}
			}
			printf("\n");
		}
		printf("\n");
	}

	return 0;
}
