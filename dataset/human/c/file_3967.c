#include <stdio.h>

int main(void) {
	int a, b, k, temp, count=0;
	scanf("%d%d%d", &a, &b, &k);

	for (temp = 100; temp > 1;temp --) {
		if (a % temp == 0 && b % temp == 0) count++;
		if (count == k)
			break;
	}
  printf("%d", temp);
  return 0;
}
