#include <stdio.h>
#include <math.h>
#include <time.h>
#include<stdlib.h>
#include<string.h>

int main(void){
	int n, k, h, ans = 0;

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d", &h);
		if (h >= k) {
			ans++;
		}
	}
	printf("%d", ans);
}
