#include <stdio.h>
int main() {
	int n, a[100000], pos = 1, cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	while (pos != 2) {
		int buf = a[pos - 1];
		a[pos - 1] = -1;
		pos = buf;
		if (pos == -1) {
			cnt = -1;
			break;
		}
		cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}
