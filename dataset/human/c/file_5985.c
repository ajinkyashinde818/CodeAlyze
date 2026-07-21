#include <stdio.h>
#include <stdint.h>

int main() {
	uint32_t dataNum, data;

	scanf("%d", &dataNum);
	scanf("%d", &data);

	uint32_t min = data;
	int32_t result = -1000000000;

	for (uint32_t i = 1; i < dataNum; i++) {
		scanf("%d", &data);

		int32_t diff = data - min;
		result = (result < diff) ? diff : result;
		min = (min > data) ? data : min;
	}
	printf("%d\n", result);
	return 0;
}
