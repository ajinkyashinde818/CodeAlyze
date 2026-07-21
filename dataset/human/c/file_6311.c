#include <stdio.h>

int main() {
	int count;
	int values[200000] = { 0 };
	int maxV, minV;
	int i;

	scanf("%d", &count);

	for (i = 0; i < count; i++) {
		scanf("%d", &values[i]);
	}

	maxV = -1000000000;
	minV = values[0];
	for (i = 1; i < count; i++) {
		maxV = values[i] - minV > maxV ? values[i] - minV : maxV;
		minV = values[i] < minV ? values[i] : minV;
	}

	printf("%d\n", maxV);

	return 0;
}
