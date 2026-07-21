#include<stdio.h>
int main(void)
{
	int s, k, x, y, z, i, cnt = 0, sum;
	scanf("%d%d", &k, &s);
	for (x = 0;x <= k;x++) {
		sum = x;
		if (sum == s) {
			cnt ++;
			break;
		}
		for (y = 0;y <= k;y++) {
			sum = x;
			sum += y;
			if (sum == s) {
				cnt ++;
				break;
			}
			z = s - x - y;
			sum += z;
			if (sum == s&&z<=k) {
				cnt++;
				//break;
			}
		}
	}
	printf("%d", cnt);
	return 0;
}
