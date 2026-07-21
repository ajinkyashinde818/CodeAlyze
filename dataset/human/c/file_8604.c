#include <stdio.h>
#include <string.h>

int main(void) {
	int n;
	int a[100000];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	int button = 1;
	int count = 0;
	for (int i = 1; i < n; i++) {
		button = a[button - 1];
		++count;
		if (button == 2) {
			printf("%d", count);
			return 0;
		}
	}

	printf("%d", -1);
	return 0;
}
