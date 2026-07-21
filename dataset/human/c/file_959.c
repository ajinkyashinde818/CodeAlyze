#include<stdio.h>
int main(void)
{
	int e, y, ans;

	scanf("%d %d", &e, &y);
	if (e == 0) {
		if (y >= 1868 && y <= 1911) {
			ans = y - 1868;
			printf("M%d\n", ans + 1);
		}
		else if (y >= 1912 && y <= 1925) {
			ans = y - 1912;
			printf("T%d\n", ans + 1);
		}
		else if (y >= 1926 && y <= 1988) {
			ans = y - 1926;
			printf("S%d\n", ans + 1);
		}
		else if (y >= 1989 && y <= 2016) {
			ans = y - 1989;
			printf("H%d\n", ans + 1);
		}
	}
	else if (e == 1) {
		ans = 1868 + y;
		printf("%d\n", ans - 1);
	}
	else if (e == 2) {
		ans = 1912 + y;
		printf("%d\n", ans - 1);
	}
	else if (e == 3) {
		ans = 1926 + y;
		printf("%d\n", ans - 1);
	}
	else if (e == 4) {
		ans = 1989 + y;
		printf("%d\n", ans - 1);
	}
	return 0;
}
