#include<stdio.h>
#include<string.h>
#include<math.h>

int main(void) {
	int n, k, h[100000];
	int i;
	int ans=0;

	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++) {
		scanf("%d", &h[i]);
	}
	for (i = 0; i < n; i++) {
		if (h[i] >= k)ans++;
	}
	printf("%d", ans);
	return 0;
}
